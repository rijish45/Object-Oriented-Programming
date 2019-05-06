 #include <iostream>
#include "funcLib.h"
#include <fstream>
#include <cctype>
#include <cmath>



extern const int ENTRIES = 23; //keeps track of entries
extern const char *INPUT_FILE_NAME = "q1Input.txt" ; //input file name
extern const char *OUTPUT_FILE_NAME = "q1Output.txt" ; //output file name


using namespace std;

int main(){

  char command;
  double first, last, delta;

initialize(); //This function prints the program output header. The output header contains the
              //name and number of the course, the semester and year, the assignment name, and the value of ENTRIES.

while (true){
cout << "Please enter command code: " ;
cin >> command;
if(tolower(command)=='q'){ //if the command is q then loop stops
  cout << "quittting...." ;
  break;
}
if(checkCode(command)==false){  //legality of command check
  cout << "Not a valid command..." << endl;
  continue;
}
if((tolower(command)!='p')&&(tolower(command)!='o')){
cout << "Please enter command parameters: " ; //only accepts command parameters if it's not p or o
cin >> first;
if(cin.get()=='\n'){
  cout << "No computation needed" << endl; //number of parameters check
  cout << endl;
  continue; //next iteration as delta and last value are undefined
}
cin >> last;
if(cin.get()=='\n') {
  cout << "No computation needed" << endl; ////number of parameters check
  cout << endl;
  continue; // next iteration as delta value is undefined
}
cin >> delta;

}

if (tolower(command)=='p'){
  readDataFromFile(INPUT_FILE_NAME); //reads from file
}
if(tolower(command)=='o'){
  writeDataToFile(OUTPUT_FILE_NAME); //writes to file
}

choice(command,first,last,delta);



}
return 0;
}
