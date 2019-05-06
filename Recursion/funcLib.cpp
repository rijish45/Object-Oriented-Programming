#include <cctype>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "funcLib.h"

using namespace std;

extern const int ENTRIES;
extern const char *INPUT_FILE_NAME ;
extern const char *OUTPUT_FILE_NAME;

/*This function prints the program output header. The output header contains the
name and number of the course, the semester and year, the assignment name, and the value of ENTRIES. */
void initialize() {
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2016" << endl;
  cout << "Programming assignment 2" << endl;
  cout << "Maximum Computation is: " << ENTRIES << endl;
  cout << endl;
}

/*This function returns true if the command code in parameter “code” is a legal code
character; otherwise, the function returns false */
bool checkCode(char user){

user = tolower(user);
if(!isalpha(user))
  return false;
else if (user=='u')
  return true;
else if (user=='c')
  return true;
else if (user=='r')
  return true;
else if (user=='d')
  return true;
else if (user=='l')
  return true;
else if (user=='s')
  return true;
else if (user=='n')
   return true;
else if (user=='e')
   return true;
else if (user=='a')
   return true;
else if (user=='y')
   return true;
else if (user=='p')
   return true;
else if (user=='o')
   return true;
else if (user=='q')
     return true;
else
    return false; //returns false if the command is not a valid one

}
//calls different function based on command
void choice (char command, double first, double last, double delta){
double value;
int nyancat =0 ;
switch(tolower(command)){

 case 'u':
      square(first,last,delta);
      cout << endl;
      break;

case 'c':
      circumference(first,last,delta);
      cout << endl;
      break;

 case 'r':
       squareroot(first,last,delta);
       cout << endl;
       break;
 case 'd':
      oddityodd(first,last,delta);
      cout << endl;
      break;

 case 'y' :
     while(first <= last && nyancat < ENTRIES){
     value = findNyanCatValue(first);
     cout << "Nyan cat value of " << first << " = " << value << endl;
     first+=delta;
     nyancat++;
   }
     cout << endl;
     break;


 case 's':
     sinangle(first,last,delta);
     cout << endl;
     break;

case  'n' :
     cosineangle(first,last,delta);
     cout << endl;
     break;

case 'e' :
     exponential(first,last,delta);
     cout << endl;
     break;

case 'a' :
     naturallog(first,last,delta);
     cout << endl;
     break;

case 'l' :
     luckynum(first,last,delta);
     cout << endl;
     break;


default:
     break;
}

}


//returns a boolean value
bool parameters(double first, double last, double delta){
  if (first > last || delta <=0){ //checks the condition whether first is greater than last and  whether delta has a legal value
    return false;
  }
 else
   return true;
}

//calculates area  of a square for given range of values
void square (double first,double last,double delta){
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
  else {
     int count = 0;
     while((first <= last) && (count < ENTRIES)){
       cout << fixed;
       cout << "Area of square with side length " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << pow(first,2.0) << endl;
       first+=delta;
       count++;
     }
   }
}
//calculates circumference of a circle for given range of values
void circumference (double first, double last, double delta) {
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
  else {
    int count = 0;
    while((first <= last) && (count < ENTRIES)){
      cout << fixed;
      cout << "Circumference of circle with radius " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << 2*3.14*first << endl;
      first+=delta;
      count++;
    }
  }
}

///calculates square root for given range of values
void squareroot(double first, double last, double delta) {
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
  else {
      int count = 0;
      while((first <= last) && (count < ENTRIES)){
        cout << fixed;
        cout << "The square root of the number " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << sqrt(first) << endl;
        first+=delta;
        count++;
      }
    }
}

//calculates and displays odd numbers between a range of values
void  oddityodd (double first, double last, double delta) {
  if (first > last) {
    cout << "No computation needed.";
    cout << endl;
    }
else {
  int i = first;
  int count = 0;
  cout << "Odd numbers between " << first << " and " << last << " is = ";
  while((count < ENTRIES) && (i <= last))  {
    if (i%2!=0){
      cout << i << " " ;
      count++;
    }
    i++;
 }
 cout << endl;
  }
}

//calculates cosine of angle for given range of values
void sinangle (double first, double last, double delta){
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
      cout << endl;
    }
    else {
        int count = 0;
        while((first <= last) && (count < ENTRIES)){
          cout << fixed;
          cout << "The sine of " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << sin(first) << endl;
          first+=delta;
          count++;
        }
      }

}

//calculates cosine of angle for given range of values
void cosineangle (double first, double last, double delta) {
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
    else {
        int count = 0;
        while((first <= last) && (count < ENTRIES)){
          cout << fixed;
          cout << "The cosine of " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << cos(first) << endl;
          first+=delta;
          count++;
        }
      }
}

//calculates exponential values for given range of values
void exponential (double first, double last, double delta) {
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
    else {
        int count = 0;
        while((first <= last) && (count < ENTRIES)){
          cout << fixed;
          cout << "The Exponential of " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << exp(first) << endl;
          first+=delta;
          count++;
        }
      }
}

//calculates natural log for given range of values
void naturallog (double first, double last, double delta) {
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
    else {
        int count = 0;
        while((first <= last) && (count < ENTRIES)){
          cout << fixed;
          cout << "The natural log of " << setprecision(2)  << first << " = " << showpoint << setprecision(4) << log(first) << endl;
          first+=delta;
          count++;
        }
      }
    }

//calculates lucky number using different number as seeds depending upon the iteration
void luckynum (double first, double last, double delta){
  if (parameters(first,last,delta)==false){
    cout << "No computation needed.";
    cout << endl;
    }
    else {
        int count = 0;
        while((first <= last) && (count < ENTRIES)){
          srand(first);
          cout << "The lucky number of " << static_cast<int>(first) << " = " << static_cast<double>(rand()) << endl;
          first+=delta;
          count++;
        }
      }
}
//The function reads the commands from a file called q1Input.txt.
void readDataFromFile(const char * filename){
  ifstream input;
  char comm;
  double begin, end, del;
  input.open(filename);
  while ( input >> comm >> begin >> end >> del){
    cout << "Successfully read data from file: Code " << comm << " First " << setprecision(2) << begin << " Finish " << end << " Delta " << del << endl;
    choice(comm,begin,end,del);

  }
input.close();

}

double findNyanCatValue(double num) {

  num = pow(3*num,num) + num;
  return num;

}

//This function will write the output of the file to a file called q1Output.txt.
void writeDataToFile(const char * filename) {
  ofstream output;
  double val;
  int counter = 0;
  output.open(filename);
  double begin = rand()%20;
  double end = 45 + rand()%31;
  double deltout = 5 + rand()%5;
  while(begin <= end && counter < ENTRIES){
  val = findNyanCatValue(begin);
  output << val << " ";
  begin+=deltout;
  counter++;
}

 cout << "file has been written..."<< endl;
 output.close();

}
