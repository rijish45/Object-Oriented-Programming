/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#include "Town_Hall.h"
#include <iostream>
#include <iomanip>

using namespace std;


Town_Hall::Town_Hall():Game_Object('t',0)
{
    id_num = 0;
    state = 'o';
    amount = 0.0;
    cout << "Town_Hall defualt constructed." << endl;

}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc): Game_Object('t', inputId)
{
    id_num = inputId;
    state = 'o';
    amount = 0.0;
    location = inputLoc;
    cout << "Town_Hall constructed" << endl;

}

Town_Hall::~Town_Hall()
{
    cout << "Town_Hall destructed" << endl;
}


//Adds the amount supplied to the gold in the Town_Hall

void Town_Hall::deposit_gold(double deposit_amount)

{
    amount += deposit_amount;
}

//If the Town_Hall has gold greater than or equal to 50, it sets the state to ‘u’ for
//“Upgraded”, change display_code to ‘T’, prints the message “Town_Hall (id
//number) has been upgraded.”

bool Town_Hall::update()

{
    if (amount >= 50.0 && state!='u')

    {
        state = 'u';
        display_code = 'T';
        cout << "Town_Hall " << id_num << " has been upgraded."<<endl;
        return true;
    }
    else
    {
        return false;
    }

}


//Prints out the status of the object

void Town_Hall::show_status()

{
    cout << "Town Hall status: ";
    cout << display_code << id_num << " at " << location;
    cout << " contains " << amount;
    cout << " of gold.";

    if (amount > 50.0)
    cout << " Upgraded." << endl;
    else
    cout << " Not yet upgraded. " << endl;
}
