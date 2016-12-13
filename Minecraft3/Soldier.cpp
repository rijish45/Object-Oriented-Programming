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
  cout << " Soldier default constructed." << endl;
}

Soldier::Soldier (int in_id, Cart_Point in_loc): Person('S', in_id, in_loc)

{
  attack_strength=2;
  range = 2;
  cout << "Soldier constructed." << endl;

}

void Soldier::start_attack(Person * in_target)
{

 if (is_alive())

 {
   double dist = cart_distance(get_location(),in_target->get_location());

   if (dist <= range)
   {

     cout << display_code << get_id() << "Clang!" << endl;
     target = in_target;
     state='a';

   }
   else if (dist > range)
   {
     cout << "Target is out of range!" << endl;
   }
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
           cout << display_code << get_id() << "Clang!"<< endl;
           target->take_hit(attack_strength);
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
     case 'a':
       cout << display_code << get_id() << ": Attacking." << endl;
   }
}


Soldier::~Soldier(){

 cout << "Soldier destructed." << endl;

}
