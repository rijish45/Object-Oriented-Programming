#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "FileFunctions.h"

using namespace std;

extern const char * INPUTFILE_NAME;  //filename declaration


void ReadDataFromFile(const char *filename, int myArray[], int &size){
  ifstream readData;
  int i =0;
  readData.open(filename);
  while(!readData.eof()){ //till the file ends, the loop iterates
    readData >> myArray[i]; //the array gets filled up
    i++;
  }
  readData.close();
  i--;
  size = i; //size gets modified as it is passed by reference
  return;

}

 void WriteRandomDataToFile(const char *filename , int N, int M){
 if (N < 0 || M < 0) {
   cout << "Please use positive integer values for M and N. " << endl;
   cout << "N and M values have been modified." << endl;
   N = abs(N); //error checking
   M = abs (M); //error checking
 }
 ofstream output;
 int number;
 output.open(filename);
 for (int i = 0; i < N; i++){
     number = rand()%(M+1); //number is between 0 to M
     output << number << " " << endl;
 }
  output.close();
 }
