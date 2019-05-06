//Problem2

#include <iostream>
#include <iomanip>
using namespace std;

int main()

{

  float tiprate; // Declaring variables for different inputs from user
  float tip;
  float posttax;
  float bill;
  cout << "Enter the original bill amount: " ; //asking user for bill amount
  cin >> bill;
  
  if (bill < 0)

  {
    cout << "PLease enter valid bill. " << endl;
    return 0;
  }
  
  float taxrate;
  cout << "Enter the tax rate %: "; //asking user for tax rate
  cin >> taxrate;

  if (taxrate < 0)

  {
    cout << "Please enter positive tax rate. " << endl;
    return 0;

  }
  
  int tiplevel;
  
  cout << "Enter tip level (1=15%,2=20%;3=25%): " ;
  cin >> tiplevel;  //depending on user choice different scenarios
  switch(tiplevel)

  {
    case 1: tiprate=15.0/100;
            break;
    case 2: tiprate=20.0/100;
            break;
    case 3: tiprate=25.0/100;
            break;
    default: cout << "Please select a valid choice." << endl;
              return 0; //error checking
    }
   
    posttax=static_cast<float>(bill+bill*(taxrate/100.0));
    int choice; //bill after adding tax
    cout << "Tip on post tax amount? (1=yes, 2=no): " ;
    cin >> choice; //depending on user choice different scenarios
    if (choice==1)

    {
      tip=posttax*tiprate;
    }
   
   else if (choice==2)

   {
      tip=bill*tiprate;
   }
    else
    {
      cout << "Choose a valid method" << endl;
      return 0;  //error checking
    }


    cout.precision(2); //setting precision for output to display two decimal digits

    cout << "The total bill pre-tip is: " << fixed <<  posttax << endl;;
    cout << "The total tip is: " << fixed << tip << endl;
    cout << "The total bill post-tax is: "  << fixed << posttax+tip   << endl;

    return 0;


}
