/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


Miner::Miner():Person('M')

{
    amount = 0;
    mine = NULL;
    home = NULL;
    cout << "Miner default constructed." << endl;
}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M', in_id, in_loc)
{
    amount = 0;
    mine = 0;
    home = 0;
    cout << "Miner constructed." << endl;
}

Miner::~Miner()

{
    cout << "Miner destructed" << endl;
}


//makes miner start mining

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)

{
  if(state!='x')
  {
    mine = inputMine;
    home = inputHome;
    setup_destination(mine->get_location());

    this->state = 'o';
    cout << "Miner "<< this->get_id() << " mining at Gold_Mine "<< mine->get_id();
    cout << " and depositing at Town_Hall " << home->get_id() << endl;
    cout << this->display_code << this->get_id() << ": Yes, My Lord." << endl;
}

else
   cout << display_code << this->get_id() << "Dead object." << endl;

}

void Miner::take_hit(int attack_strength, Person *attacker_ptr)
{

  Person::take_hit(attack_strength, attacker_ptr);

	if (get_health() > 0)
	{
		Cart_Point attacker_location = attacker_ptr->get_location();
		Cart_Vector attacker_direction = location - attacker_location;
		double scale = 1.5;
		attacker_direction = attacker_direction * scale;
		Cart_Point flee_location = location + attacker_direction;
    cout << display_code << get_id() << ": I dont want to fight!" << endl;
		start_moving(flee_location);
	}
}

//returns bool value depending on change of state

bool Miner::update()

{
    switch (state)

    {
        case 's':
            break;

        case 'm':
            if(update_location())
            {
                stop();
                state = 's';
                return true;
            }
            else
            return false;
            break;

        case 'o':
            if(update_location())

            {
                state = 'g';
                return true;
            }
            else
            return false;
            break;


        case 'g':
            amount = mine->dig_gold(35.0);
            cout << display_code << get_id() <<": Got " << amount << " gold."<<endl;
            setup_destination(home->get_location());
            state = 'i';
            return true;
            break;


        case 'i':
            if(update_location())

            {
                state = 'd';
                return true;
            }
            else
            return false;
            break;

        case 'd':
            cout << display_code << get_id() << ": Deposited " << amount;
            cout << " of gold." << endl;
            home->deposit_gold(amount);
            amount = 0;

            if(mine->is_empty())

            {
                stop();
                state = 's';
                cout<< display_code << get_id() <<": More work?" <<endl;
            }
            else
            {
                setup_destination(mine->get_location());
                state = 'o';
                cout<< display_code << get_id() <<": Going back for more."<<endl;
            }

            return true;
            break;

          case 'x':
    					state='x';
    					return false;
    					break;
    }
}

//shows status of Miner based on different states

void Miner::show_status()
{
cout << "Miner status: ";
Person::show_status();

    switch (state)

    {

        case 's':
          cout << " Stopped" << endl;

        case 'o':
            cout << " is outbound to a mine." << endl;
            break;

        case 'g':
            cout << " is getting gold from mine."<< endl;
            break;

        case 'i':
            cout << " is inbound to home with load: "<< amount << endl;
            break;

        case 'd':
            cout << " is depositing gold"<< endl;
            break;
    }
}
