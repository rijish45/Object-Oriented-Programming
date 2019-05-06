
/* Created by Rijish Ganguly
  for EC 327, Fall of 2016
  U65638769
*/

#include "Gold_Mine.h"

//default constructor

Gold_Mine::Gold_Mine():Game_Object('G',0)

{

   id_num = 0;
   state = 'f';
   amount = 100.0;
   cout << "Gold_Mine default constructed" << endl;

}


double Gold_Mine::get_gold_amount ()

{

  return amount;

}
//calls specific gameobject constructor

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G', inputId, inputLoc)

{

   state = 'f';
   amount = 100.0;
   id_num = inputId;
   location = inputLoc;
   cout << "Gold_Mine constructed" << endl;

}

Gold_Mine::~Gold_Mine()

{
   cout << "Gold_Mine destructed" << endl;

}


//checks if mine is empty or not

bool Gold_Mine::is_empty()
{
 if (amount == 0)
 {
   return true;
 }
 else
 {
   return false;
  }
}


//returns amount to dig based on requirements

double Gold_Mine::dig_gold(double amount_to_dig = 35.0)
{
   if (amount >= amount_to_dig)
   {
       amount -= amount_to_dig;
       return amount_to_dig;
   }

else

   {
       double temp = amount;
       amount = 0;
       return temp;
   }

}

//updates the gold mine based on it's present state
//returns false if it's  not depleted

bool Gold_Mine::update()
{
   if(is_empty() && state!= 'e')
   {
       state = 'e';
       display_code = 'g';
       cout << "Gold_Mine " << id_num << " has been depleted."<<endl;
       return true;
   }
   else
       return false;
}

//prints status for object

void Gold_Mine::show_status()
{
   cout << "Gold Mine Status: ";
   cout << display_code << id_num << " at location " << location;
   cout << setprecision(5);
   cout << " Contains " << amount << "." <<endl;

}
