
//Problem1

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int X1, Y1, X2, Y2, X3, Y3; //declaring variables for co=ordinates
  cout << "Please enter three x,y coordinates:" << endl;
  cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3; //user input
  float slope;
  if(X2!=X1){ //slope is undefined for vertical line
    slope=(Y2-Y1)/(X2-X1); //slope calculation
  }
  else{
    cout << "The line is the Y axis" << endl;
}
float A= -(slope); //the line is of the form Ax+By+c=0
float B= 1.00;
float C= slope*X1-Y1;
float sum = abs(A*X3+B*Y3+C);
float denom = sqrt(pow(A,2.0)+pow(B,2.0)); //The equation is |Ax+By+C|/(A^2+B^2)^1/2
float dist = sum/denom;

cout << "The shortest distance for (" << X3 << "," << Y3 << ")" << " to the line composed of (" << X1 << "," << Y1 << ")"  << " and (" <<  X2 << "," << Y2 << ")" <<  " is " << dist << endl;

return 0;
}
