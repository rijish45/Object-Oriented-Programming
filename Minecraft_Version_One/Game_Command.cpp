/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#include "Miner.h"
#include "Game_Command.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <exception>

void do_move_command (Model& model, View& view, int id, double x, double y)

{
    Cart_Point destination(x, y);
    //cout << "Moving Miner " << id << " to " << destination << endl;

   if(id==1||id==2||id==3||id==4)
   {
    model.get_Person_ptr(id)->start_moving(destination);
    model.display(view);
   }

   else
    cout << "Incorrect object id" << endl;

}

//Commands miner to start work

void do_work_command(Model& model, View& view, int id1, int id2, int id3)
{
    //cout << "Miner "<< id1 << " mining at Gold_Mine " << id2;
    //cout <<" and depositing at Town_Hall "<< id3 << endl;
if(id1==1||id1==2 && id2==1||id2==2 && id3==1)

{
    Gold_Mine* mine = model.get_Gold_Mine_ptr(id2);
    Town_Hall* home = model.get_Town_Hall_ptr(id3);
    Person* miner = model.get_Person_ptr(id1);

    static_cast<Miner*>(miner)->start_mining(mine, home);
    model.display(view);

  }


  else if(id1==3||id1==4 && id2==1 ||id2==2 && id3==1 )
  {
    model.get_Person_ptr(id1)->start_mining();
    model.display(view);

  }

  else if(id1!=1 || id1!=2 || id1!=3 || id1!=4 || id2!=1 || id2!=2 && id3!=1)
		{
			cout<<"Incorrect object id "<<endl;
		}

}

//Stops a miner

void do_stop_command (Model& model,View& view, int id)

{
  if(id==1||id==2||id==3||id==4)
  {

    model.get_Person_ptr(id)->stop();
    model.display(view);

  }
else if (id!=1||id!=2||id!=3||id!=4)
     cout << "Incorrect object id" << endl;
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

	if (attacker_ptr == NULL)
	 cout << "Invalid ID." << endl;
	else
 {
		Person *target_ptr = model.get_Person_ptr(targetid);
    if (target_ptr == NULL)
	    cout << "Invalid ID." << endl;
    else
		  attacker_ptr->start_attack(target_ptr);
	}
}
