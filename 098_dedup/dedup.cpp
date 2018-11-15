#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

size_t hasher(std::ifstream & input, string filepath) {
  string line;
  size_t hashval;
  string input_data;
  hash<std::string> str_hash;
  while (!input.eof()) {
    getline(input, line);
    input_data.append(line);
  }
  hashval = str_hash(input_data);
  return hashval;
}

void file_compare(pair<size_t, string> curr_pair, unordered_map<size_t, std::string> & myhashmap) {
  std::unordered_map<size_t, std::string>::iterator it = myhashmap.find(curr_pair.first);
  if (it == myhashmap.end()) {
    myhashmap.insert(curr_pair);
  }
  else {
    std::cout << "#Removing " << curr_pair.second << " (duplicate of " << it->second << ")."
              << std::endl;
    std::cout << "rm " << curr_pair.second << std::endl;
  }
}

void dir_recursor(const string & dir, std::unordered_map<size_t, std::string> & myhashmap) {
  DIR * curr_dir;
  struct dirent * ent;
  if ((curr_dir = opendir(dir.c_str())) == 0) {
    perror("Could not open directory!");
    closedir(curr_dir);
    exit(EXIT_FAILURE);
  }
  else {
    while ((ent = readdir(curr_dir)) != NULL) {
      string file_name(ent->d_name);
      if (file_name == "." || file_name == "..") {
        continue;
      }
      else if (ent->d_type == DT_DIR) {
        string next_dir = dir + "/" + file_name;
        dir_recursor(next_dir, myhashmap);
      }
      else if (ent->d_type == DT_REG) {
        string file = dir + "/" + file_name;
        ifstream input(file.c_str());
        if (input.good()) {
          size_t curr_hash;
          curr_hash = hasher(input, file);
          pair<size_t, string> curr_pair(curr_hash, file);
          file_compare(curr_pair, myhashmap);
        }
        else {
          cout << "Can not open the file!" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
      else {
        std::cerr << "Unknown file type. " << file_name << " will be omitted." << std::endl;
      }
    }
  }
  closedir(curr_dir);
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    perror("Usage: ./dir (the directory to be dedup-ed). Please re-run the program!");
    return EXIT_FAILURE;
  }
  else {
    unordered_map<size_t, std::string> my_hash_map;
    int i = 1;
    std::cout << "#!/bin/bash" << std::endl;
    while (i < argc) {
      const string dir = argv[i];
      dir_recursor(dir, my_hash_map);
      i++;
    }
  }
  return EXIT_SUCCESS;
}
