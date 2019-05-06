/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/


#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <ostream>
#include <iomanip>


Cart_Vector::Cart_Vector()

{
    x = 0.0;
    y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)

{
    x = inputx;
    y = inputy;
}



//Overloaded Operators

Cart_Vector operator*(Cart_Vector v1, double d)

{

    v1.x = v1.x * d;
    v1.y = v1.y * d;
    return v1;

}

Cart_Vector operator/(Cart_Vector v1, double d)

{

    v1.x = v1.x/d;
    v1.y = v1.y/d;
    return v1;

}

ostream& operator << (ostream& out, const Cart_Vector& v1)

{

    out << setprecision(6);
    out << "<" << v1.x << ", " << v1.y << ">";
    return out;
}
