/*
Rijish Ganguly
rg239
Assignment 60
*/

#include <ctype.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

//function prototypes
void Time_Display(struct stat st);
void fixDevice(struct stat st);
void symbolic_link(struct stat st, char * file);

//This function is for Step 4
char * time2str(const time_t * when, long ns) {
  char * ans = malloc(128 * sizeof(*ans));
  char temp1[64];
  char temp2[32];
  const struct tm * t = localtime(when);
  strftime(temp1, 512, "%Y-%m-%d %H:%M:%S", t);
  strftime(temp2, 32, "%z", t);
  snprintf(ans, 128, "%s.%09ld %s", temp1, ns, temp2);
  return ans;
}

void Stat(char * file) {
  struct stat st;

  if (lstat(file, &st) == -1) {
    fprintf(stderr, "stat: cannot stat '%s': No such file or directory\n", file);
    exit(EXIT_FAILURE);
  }

  const char * filetype;
  const char * firstletter;
  char permission[10];
  char output[11];

  long unsigned int user_id = st.st_uid;   //storing user id
  long unsigned int group_id = st.st_gid;  //storing gid

  //find out the type of the file
  switch (st.st_mode & S_IFMT) {
    case S_IFBLK:  //block special
      filetype = "block special file";
      firstletter = "b";
      break;
    case S_IFCHR:  //character
      filetype = "character special file";
      firstletter = "c";
      break;
    case S_IFDIR:  //directory
      filetype = "directory";
      firstletter = "d";
      break;
    case S_IFIFO:  //fifo
      filetype = "fifo";
      firstletter = "p";
      break;
    case S_IFLNK:  //symbolic link
      filetype = "symbolic link";
      firstletter = "l";
      break;
    case S_IFREG:  //regular file
      filetype = "regular file";
      firstletter = "-";
      break;
    case S_IFSOCK:  //socket
      filetype = "socket";
      firstletter = "s";
      break;
    default:  //unknown file type
      filetype = "unknown?";
  }

  //User permissions//

  if (st.st_mode & S_IRUSR)
    permission[0] = 'r';
  else
    permission[0] = '-';
  if (st.st_mode & S_IWUSR)
    permission[1] = 'w';
  else
    permission[1] = '-';
  if (st.st_mode & S_IXUSR)
    permission[2] = 'x';
  else
    permission[2] = '-';

  //Group permissions//

  if (st.st_mode & S_IRGRP)
    permission[3] = 'r';
  else
    permission[3] = '-';
  if (st.st_mode & S_IWGRP)
    permission[4] = 'w';
  else
    permission[4] = '-';
  if (st.st_mode & S_IXGRP)
    permission[5] = 'x';
  else
    permission[5] = '-';

  //Other permissions//

  if (st.st_mode & S_IROTH)
    permission[6] = 'r';
  else
    permission[6] = '-';
  if (st.st_mode & S_IWOTH)
    permission[7] = 'w';
  else
    permission[7] = '-';
  if (st.st_mode & S_IXOTH)
    permission[8] = 'x';
  else
    permission[8] = '-';
  permission[9] = '\0';

  //Generate the ouptut string by combining the permissions ans first letter depending on the file type
  strcpy(output, firstletter);
  strcat(output, permission);
  //printf("%s\n", output);

  struct passwd * username = getpwuid(user_id);
  struct group * groupname = getgrgid(group_id);

  symbolic_link(st, file);  //step 7 function

  printf("  Size: %-10lu\tBlocks: %-10lu IO Block: %-6lu %s\n",
         st.st_size,
         st.st_blocks,
         st.st_blksize,
         filetype);

  fixDevice(st);  //function to modify the device discrepancy

  printf("Access: (%04o/%s)  Uid: (%5d/%8s)   Gid: (%5d/%8s)\n",
         (st.st_mode & ~S_IFMT),
         output,
         (int)user_id,
         username->pw_name,
         (int)group_id,
         groupname->gr_name);

  Time_Display(st);  //Display the modify, access and change time
}

void fixDevice(struct stat st) {
  if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode)) {
    printf("Device: %lxh/%lud\tInode: %-10lu  Links: %-5lu Device type: %x,%x\n",
           st.st_dev,
           st.st_dev,
           st.st_ino,
           st.st_nlink,
           major(st.st_rdev),  //Had to include the headerfile <sys/sysmacros.h>
           minor(st.st_rdev));
  }
  else {
    printf("Device: %lxh/%lud\tInode: %-10lu  Links: %lu\n",
           st.st_dev,
           st.st_dev,
           st.st_ino,
           st.st_nlink);
  }
}

void symbolic_link(struct stat st, char * filename) {
  if (S_ISLNK(st.st_mode)) {
    char buffer[256];
    ssize_t len = readlink(filename, buffer, 256);
    buffer[len] = '\0';  //appending the \0
    printf("  File: %s -> %s\n", filename, buffer);
  }
  else
    printf("  File: %s\n", filename);  //for non-symbolic files
}

void Time_Display(struct stat st) {
  char * timestr = time2str(&st.st_atime, st.st_atim.tv_nsec);
  printf("Access: %s\n", timestr);
  free(timestr);

  timestr = time2str(&st.st_mtime, st.st_mtim.tv_nsec);
  printf("Modify: %s\n", timestr);
  free(timestr);

  timestr = time2str(&st.st_ctime, st.st_ctim.tv_nsec);
  printf("Change: %s\n", timestr);
  free(timestr);

  printf(" Birth: -\n");
}

int main(int argc, char * argv[]) {
  if (argc == 1)  //check the number of input parameters
  {
    fprintf(stderr, "stat: missing operand\nTry running with a filename.\n");
    exit(EXIT_FAILURE);
  }
  //iterate over all the command line input files
  for (int i = 1; i < argc; i++) {
    Stat(argv[i]);
  }

  return EXIT_SUCCESS;
}
