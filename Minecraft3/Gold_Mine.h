/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/


#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include <iomanip>
#include <iostream>


using namespace std;

class Gold_Mine:public Game_Object{
public:


//constructors

    Gold_Mine();
    Gold_Mine(int, Cart_Point);
    ~Gold_Mine();

// member functions
    bool is_empty();
    double dig_gold(double);
    bool update();
    void show_status();


private:

  //private fields/members

    int id_num;
    double amount;

};

#endif
