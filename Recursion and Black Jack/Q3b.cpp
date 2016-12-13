#include <iostream>
using namespace std;
double ret= 0.0000; //global variable


double recursive(int n){
if (n==1){ //base case
  return 2/5.0;

}
else {
  ret = 2*n/static_cast<double>((3*n+2)) + recursive(n-1); //recursive call
  return ret;
}
}



int main (){
  int n;
  cout << "Enter n: " ;
  cin >> n;
  if (n <= 0 || cin.fail()){ //error checking
    cout << "Please enter a non-zero positive integer. Invalid input." << endl;
    return 0;
    }

  cout.precision(6);
  double result = recursive(n);
  cout << result << endl;


  return 0;
}
