/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/




#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>
#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
using namespace std;

class Soldier: public Person
{

	private:
		int attack_strength;
		double range;
		Person *target;


	public:

		Soldier();
		Soldier(int, Cart_Point);
		void start_attack(Person * in_target);
		bool update();
		void take_hit(int attack_strength, Person *attacker_ptr);
		void show_status();
		~Soldier();
};

#endif
