/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/


#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Person.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Person::Person(char in_code):Game_Object(in_code,0)

{
    speed = 5.0;
    health = 5;
    destination = Cart_Point();
    delta = Cart_Vector();
}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code, in_id, in_loc)

{
    speed = 5;
    health = 5;
    destination = Cart_Point();
    delta = Cart_Vector();
}


void Person::show_status()

{
		Game_Object::show_status();

    switch(state)
		{
			case 's':
				if (is_alive())

        {
					cout << "moving at speed of " << speed << " towards " << destination << " at each step of " << delta << "." << endl;
					cout << "Stopped." << endl;

        }
				break;
			case 'm':
				if(is_alive())
				{
					cout << "moving at speed " << speed << " to " << destination << " at each step of  "<< delta << "." << endl;
				}

      else if(!is_alive())
				{
				cout << "moving at speed " << speed << " to " << destination << endl << " at each step of " << delta << " is dead." << endl;
				}
       break;
      case 'x':

        cout << "moving at speed " << speed << " to " << destination << endl << " at each step of " << delta << " is dead." << endl;
				break;
		}

}

Person::~Person()

{

    cout << "Person destructed" << endl;
}


double Person::get_speed()

{
    return speed;

}


bool Person::is_alive()
{
  if (state=='x')
  	{
  		return false;
  	}
  else
    {
  		return true;
  	}

}



void Person::take_hit(int attack_strength)

{
	health = health - attack_strength;
	if (health <= 0)
	{
		cout << display_code << get_id() << "Arrggh!" << endl;
		state='x';
	}
	else
	{
		cout << display_code << get_id() << ": Ouch!" << endl;
	}

}



Cart_Point Person::get_destination()

{
    return destination;

}

Cart_Vector Person::get_delta()

{
    return delta;
}

//sets up delta

void Person::setup_destination(Cart_Point dest)

{
    destination = dest;
    delta = (dest - location)*(speed / cart_distance(dest,location));

}

void Person::start_moving(Cart_Point dest)

{
    if(is_alive())
    {

    setup_destination(dest);
    if(dest.x == location.x && dest.y == location.y)

    {
        cout << display_code << get_id() << ": I'm already there. See?"<<endl;
    }


    else
    {
        this->state = 'm';
        cout << "Moving "<< get_id() <<" to " << destination << endl;
        cout << display_code << get_id() <<": On my way."<<endl;
    }

  }
  else
     cout << display_code << get_id() << ": The object is dead." << endl;
}



void Person::start_attack(Person * attack)
{

  if(is_alive())
  	{
  		cout << display_code << get_id() << ": I can't attack."<<endl;
  	}

    if(!is_alive())
  	{
  		cout << display_code << get_id() <<  ": I can't attack. I'm also dead." << endl;
  	}

}

void Person::stop()

{
    state = 's';
    cout << "Stopping "<< get_id() << endl;
    cout << display_code << get_id() <<": All right."<<endl;
}

bool Person::update_location()
{

    if((abs(delta.x) >= abs(destination.x - location.x)) && (abs(delta.y) >= abs(destination.y - location.y)))
    {
        location.x = destination.x;
        location.y = destination.y;
        cout << display_code<<get_id() << ": I'm there!" << endl;
        return true;
    }
    else
    {
        location = location + delta;
        cout << display_code << get_id() <<": step..."<<endl;
        return false;
    }
}

void Person::start_mining()
{
    cout << "Sorry, I can't work a mine." << endl;
}
