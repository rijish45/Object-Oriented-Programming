/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/



#include "Soldier.h"
#include <iostream>

using namespace std;


Soldier::Soldier():Person('S')

{
  attack_strength = 2;
  range = 2;
  target = NULL;
  cout << " Soldier default constructed." << endl;
}

Soldier::Soldier (int in_id, Cart_Point in_loc): Person('S', in_id, in_loc)

{
  attack_strength=2;
  range = 2;
  target = 0;
  cout << "Soldier constructed." << endl;

}

void Soldier::take_hit(int attack_strength, Person *attacker_ptr)
{
	Person::take_hit(attack_strength, attacker_ptr);
  start_attack(attacker_ptr);

}

void Soldier::start_attack(Person * in_target)
{
	if (is_alive())
	{
		if (in_target->get_id() == this->get_id())
		{
			cout << display_code << get_id() << ": I cannot attack myself!" << endl;
			state = 's';
		}
		else
		{

			double dist = cart_distance(in_target->get_location(), location);
      if (dist <= range)
			{
				target = in_target;
				cout << display_code << get_id() << ": Attacking." << endl;
				state = 'a';
			}

      else
				cout << display_code << get_id() << ": Target is out of range." << endl;
		}
	}
	else
	{
		cout << display_code << get_id() << ": I am dead." << endl;
	}

}



bool Soldier::update()
{
 switch(state){

     case 'x':
       return false;
       break;

     case 's':
       return false;
       break;

     case 'm':

       if(update_location())
         {
           state='s';
           return true;

         }
         else
         {
           state='m';
           return false;
         }
       break;


     case 'a':

       double dist=cart_distance(get_location(),(*target).get_location());
       if(dist<=range)
       {
         if(target->state=='x')
         {
           cout << display_code << get_id()<<": I triumph."<<endl;
           state='s';
           return true;
         }
         if (target->state!='x')

         {
           cout << display_code << get_id() << ": Clang!"<< endl;
           target->take_hit(attack_strength, this);
           state='a';
           return false;

         }
       }
       else if (dist > range)
       {
         cout << display_code << get_id() << ": Target is out of range." << endl;
         state='s';
         return true;
       }
 }
}

void Soldier::show_status()
{
   cout << "Soldier status: ";
   Person::show_status();
   switch(state)
   {
     case 's' :
       cout << "Stopped" << endl;
       break;
     case 'm' :
       cout << "Moving at speed." << endl;
       break;
     case 'a':
       cout << ": Attacking." << endl;
       break;
   }
}


Soldier::~Soldier(){

 cout << "Soldier destructed." << endl;

}
