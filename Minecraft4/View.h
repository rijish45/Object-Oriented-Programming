/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#ifndef VIEW_H
#define VIEW_H

#include "Cart_Point.h"
#include "Game_Object.h"

const int view_maxsize = 20;

class View

{

public:

    View();
    void clear();
    void plot(Game_Object* ptr);
    void draw();

private:
    int size;
    double scale;
    Cart_Point origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int&, int&, Cart_Point);
};


#endif
