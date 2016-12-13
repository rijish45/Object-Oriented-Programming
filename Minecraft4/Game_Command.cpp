/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#include "Miner.h"
#include "Game_Command.h"
#include <cmath>
#include "Cart_Point.h"
#include <iostream>
#include <iomanip>
#include "Input_Handling.h"
#include <exception>




void do_new_command(Model& model, char type, int object, double x, double y)

{

    model.handle_new_command(type, object, x, y);

}





void do_move_command (Model& model, View& view, int id, double x, double y)

{

    Person * ptr = model.get_Person_ptr(id);

   if (ptr == 0)

    throw Invalid_Input("Incorrect Object ID");

	else

  {
		ptr->start_moving(Cart_Point(x,y));
    model.display(view);
  }

}



//Commands miner to start work

void do_work_command(Model& model, View& view, int id1, int id2, int id3)
{
    //cout << "Miner "<< id1 << " mining at Gold_Mine " << id2;
    //cout <<" and depositing at Town_Hall "<< id3 << endl;

    Gold_Mine* mine = model.get_Gold_Mine_ptr(id2);
    Town_Hall* home = model.get_Town_Hall_ptr(id3);
    Person* miner = model.get_Person_ptr(id1);



    if (mine == 0 || miner == 0 || home == 0)
    		throw Invalid_Input("Invalid ID entered.");

      else
    		miner->start_mining(mine, home);
        model.display(view);
}

//Stops a miner

void do_stop_command (Model& model,View& view, int id)

{

  Person *ptr = model.get_Person_ptr(id);
	if (ptr == 0)
		throw Invalid_Input("Invalid ID entered.");

  else
		ptr->stop();
    model.display(view);
}


//Updates all objects present

bool do_go_command(Model& model, View& view)

{

    cout << "Advancing one tick." << endl;
    bool change = model.update();
    model.show_status();
    model.display(view);
    return change;

}


void do_run_command(Model& model, View& view)

{
    cout << "Advancing to next event" << endl;
    int count = 0;
    bool del = false;

    do {
        del = model.update();
        count++;
    }
      while (!del && count < 5);
      model.show_status();
      model.display(view);
}

//Shows the status of all objects

void do_list_command (Model& model, View& view)

{
    model.show_status();
    model.display(view);
}



//attack command

void do_attack_command(Model & model, int attackid, int targetid)
{

	Person *attacker_ptr = model.get_Person_ptr(attackid);

	if (attacker_ptr == 0)
	 throw Invalid_Input("Incorrect Object ID for attacker");

	else
 {
		Person *target_ptr = model.get_Person_ptr(targetid);
    if (target_ptr == 0)
         throw Invalid_Input("Incorrect Object ID for target.");

    else
		  attacker_ptr->start_attack(target_ptr);
	}
}
