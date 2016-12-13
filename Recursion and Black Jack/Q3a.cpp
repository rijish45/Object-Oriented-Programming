#include <iostream>
using namespace std;

//gcd function that calls itself
int gcd (int m, int n){
  if (m % n == 0){
    return n;
  }
  else{
  gcd(n, m % n); //recursive call
}
}



int main(){
  int n, m;
  cout << "Enter m: " ;
  cin >> m;
  cout << "Enter n: ";
  cin >> n;
  if (m <= 0 || n <=0){  //error checking
      cout << "Please enter positive numbers only. " << endl;
      return 0;
    }
  int result = gcd(m,n);
  cout << "GCD is: " << result << endl;

  return 0;

}
