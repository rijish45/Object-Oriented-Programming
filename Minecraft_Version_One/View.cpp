/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/
#include "Cart_Point.h"
#include "Game_Object.h"
#include "View.h"

#include <iostream>
#include <iomanip>

using namespace std;

View::View()

{

    size = 11;
    scale = 2;
    origin = Cart_Point();
}

void View::clear()

{
    for(int i = 0; i < size; i++)

    {
        for(int j = 0; j < size; j++)

        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

bool View::get_subscripts(int &cordx, int &cordy, Cart_Point location)

   {
     cordx = int((location.x-origin.x)/scale);
     cordy = int((location.y-origin.y)/scale);

     if ((cordx <= (size*scale)) && (cordy <= (size*scale)))
       return true;

     else
     {
       cout << "An object is outside the display" << endl;
       return false;
     }
   }

void View::plot(Game_Object* ptr)

{
    int ix = 0, iy = 0;
    Cart_Point loc = ptr->get_location();
    bool valid = get_subscripts(ix, iy, loc);
   if(valid)
     if (grid[ix][iy][0]=='.' && grid[ix][iy][1]==' ')
       ptr->drawself(grid[ix][iy]);
   else
     {
      grid[ix][iy][0] = '*';
      grid[ix][iy][1] = ' ';

      }

}


void View::draw()
{
  int num = (int)scale;
  for (int y = (size - 1); y >= 0; y--)
  {

    if ( y % num  == 0)
      cout << setw(2) << left <<  y*scale;
    else
      cout << "  ";

    for (int x = 0; x < size; x++)
    {
      cout << grid[x][y][0];
      cout << grid[x][y][1];
    }
    cout << endl;
  }

  cout << "  ";
  for (int j = 0; j < size; j++)
  {
    if ( j % num == 0)
      cout << setw(4) << left << j * scale;
  }
  cout << endl;
}
