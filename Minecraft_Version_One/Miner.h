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

class Miner:public Person

{

public:
    Miner();
    Miner(int, Cart_Point);
    ~Miner();

    void show_status();
    void start_mining(Gold_Mine*, Town_Hall*);
    bool update();

private:

    double amount;
    Gold_Mine* mine;
    Town_Hall* home;
};
