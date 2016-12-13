/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#ifndef PERSON_H
#define PERSON_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"

class Person:public Game_Object{
public:


friend class Soldier;

    //constructors
    Person(char);
    Person(char, int, Cart_Point);
    virtual ~Person();

    //member functions
    void start_moving(Cart_Point);
    void stop();
    //double get_speed();
    bool is_alive();
    int get_health();
    void show_status();
    virtual void start_attack(Person * target );
    virtual void take_hit(int attack_strength, Person *attacker_ptr);
    //Cart_Point get_destination();
    Cart_Vector get_delta();
    virtual void start_mining(Gold_Mine *, Town_Hall *);

protected:
    bool update_location();
    void setup_destination(Cart_Point);

private:
    double speed;
    int health;
    Cart_Point destination;
    Cart_Vector delta;
};


#endif
