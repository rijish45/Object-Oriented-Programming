#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FileFunctions.h"
#include "Statistics.h"
using namespace std;

extern const char * INPUTFILE_NAME = "numbers.txt";  //filename


int main(){



  srand(time(0)); //seed
  int N = rand()%1000;  //can be modified by user
  int M = rand()%10;    //can be modified by user
  WriteRandomDataToFile(INPUTFILE_NAME, N, M);



 int size = 0;
 int*  myArray= new int[1000]; // since the file size can be between 0 and 1000
 ReadDataFromFile(INPUTFILE_NAME, myArray, size);
 cout << "Array size is " << size << endl;

float mean  = getMean(myArray,size); //calculates mean
cout << "Mean is: " << mean << endl;
float stdDev = getStDev(myArray,size); //calculates standard deviation
cout << "StDev is: " << stdDev << endl;






  return 0;
}
