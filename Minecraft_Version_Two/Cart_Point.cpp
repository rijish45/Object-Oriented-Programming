/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <cmath>
#include <ostream>
#include <iomanip>

using namespace std;


Cart_Point::Cart_Point()

{
    x = 0.0;
    y = 0.0;
}


Cart_Point::Cart_Point(double inputx, double inputy)

{
    x = inputx;
    y = inputy;
}


//returns distance between two points

double cart_distance(Cart_Point p1, Cart_Point p2)

{

  double distance = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
  return distance;

}




Cart_Point operator+(Cart_Point p1 ,Cart_Vector v1)
{
    Cart_Point vec;
    vec.x = p1.x + v1.x;
    vec.y = p1.y + v1.y;
    return vec;
}

Cart_Vector operator-(Cart_Point p1, Cart_Point p2)

{
    return Cart_Vector(p1.x - p2.x, p1.y - p2.y);
}

ostream& operator<<(ostream& out, const Cart_Point& p1)

{

    out << setprecision(4);
    out << "(" << p1.x << ", " << p1.y << ")";
    return out;

}
