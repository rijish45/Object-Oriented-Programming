/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#include "Game_Object.h"
#include "Cart_Point.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;


Game_Object::Game_Object(char in_code, int in_id)

{
    display_code = in_code;
    id_num = in_id;
    location = Cart_Point();
    cout << "Game_Object default constructed" << endl;
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)

{
    display_code = in_code;
    id_num = in_id;
    location.x = in_loc.x;
    location.y = in_loc.y;
    cout << "Game_Object constructed" << endl;
}

Game_Object::~Game_Object()

{
    cout << "Game_Object destructed" << endl;
}


Cart_Point Game_Object::get_location()

{
    return location;
}

int Game_Object::get_id()

{
    return id_num;
}

void Game_Object::show_status()

{
    cout << display_code << id_num << " at location " << location << endl;
}


void Game_Object::drawself(char* ptr)
{
        ptr[0] = display_code;
        ptr[1] = char(48 + id_num);
}

bool Game_Object::is_alive()

{
	return true;
}
