/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/


#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Miner.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include "Input_Handling.h"

#include <cmath>
#include <iostream>
#include <iomanip>

int main()


{

  //We need two objects to control the entire game

    Model model;
    View view;

    model.show_status();
    model.display(view);


    char command = ' ';
    char type;
    int num1;
    double num2, num3;
    int num4;

    while (command != 'q')

     {

        cout << "Enter a command: ";
        cin >> command;

if(command != 'l' && command != 'g' && command != 'r' && command != 'q' && command != 's' && command!= 'n' && command!= 'a')

        {
            cin >> num1 >> num2 >> num3;
        }

        else if(command == 's')
            cin >> num1;
        else if(command == 'a')
          cin >> num1 >> num4 ;
        else if (command == 'n')
            cin >> type >> num4 >> num2 >> num3;

try {
        switch(command)

        {

           case 'a':
              do_attack_command(model,num1,num4);
              break;

           case 'n' :
             do_new_command(model,type,num4,num2,num3);
             model.display(view);
             break;

            case 'm':
                do_move_command(model, view, num1, num2, num3);
                break;

            case 'w':
                do_work_command(model, view, num1, num2, num3);
                break;

            case 's':
                do_stop_command(model, view, num1);
                break;

            case 'g':
                do_go_command(model, view);
                break;

            case 'r':
                do_run_command(model, view);
                break;

            case 'l':
                do_list_command(model, view);
                break;

            case 'q':
                cout << "Quitting Program." << endl;
                break;
        }
  }

  catch (Invalid_Input &e)

    {
			cout << "Invalid input - " << e.msg_ptr << endl;
			continue;
		}

  }

      return 0;
}
