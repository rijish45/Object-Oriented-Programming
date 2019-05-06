/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/


#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Cart_Point.h"
#include "Cart_Vector.h"

//virtual class with pure virtual function
class Game_Object

{
   public:

    Game_Object(char, int);
    Game_Object(char, int, Cart_Point);

    virtual ~Game_Object();

    Cart_Point get_location();
    virtual bool is_alive();
    virtual int get_id();
    virtual void show_status();
    virtual bool update() = 0; //pure virtual function
    void drawself(char*);

//does get inherited to derived classes
protected:

    Cart_Point location;
    char display_code;
    char state;

private:
    int id_num;
};



#endif
