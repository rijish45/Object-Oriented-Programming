/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#ifndef CART_POINT_H
#define CART_POINT_H
#include <stdio.h>
#include <ostream>
#include "Cart_Vector.h"

using namespace std;

//default constructor
class Cart_Point

{

 public:
    double x;
    double y;
// public member functions
    Cart_Point();
    Cart_Point(double, double);
};

//non-member overloaded function;


double cart_distance(Cart_Point, Cart_Point);
Cart_Point operator+(Cart_Point, Cart_Vector);
Cart_Vector operator-(Cart_Point, Cart_Point);
ostream& operator<<(ostream&, const Cart_Point&);

#endif
