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
#include "View.h"
#include "Soldier.h"

#include <cmath>
#include <iostream>
#include <iomanip>

//creates all the required objects for the game;

Model::Model()

{

    time = 0;

    Cart_Point miner1loc(5,1);
    Cart_Point miner2loc(10,1);
    Cart_Point mine1loc(1,20);
    Cart_Point mine2loc(10,20);
    Cart_Point hallloc(0,0);
    Cart_Point soldier1loc(5,15);
    Cart_Point soldier2loc(10,15);



    num_objects = 7;
    num_persons = 4;
    num_mines = 2;
    num_halls = 1;



    person_ptrs[0] = new Miner(1, miner1loc);
    person_ptrs[1] = new Miner(2, miner2loc);
    person_ptrs[2] = new Soldier(3, soldier1loc);
    person_ptrs[3] = new Soldier(4, soldier2loc);


    mine_ptrs[0] = new Gold_Mine(1, mine1loc);
    mine_ptrs[1] = new Gold_Mine(2, mine2loc);
    hall_ptrs[0] = new Town_Hall(1, hallloc);


    object_ptrs[0] = person_ptrs[0];
    object_ptrs[1] = person_ptrs[1];
    object_ptrs[2] = mine_ptrs[0];
    object_ptrs[3] = mine_ptrs[1];
    object_ptrs[4] = hall_ptrs[0];
    object_ptrs[5] = person_ptrs [2];
    object_ptrs[6] = person_ptrs[3];

    cout  << "Model default constructed." << endl;
}


//destroys all game objects

Model::~Model()

{
    for(int i = 0; i < num_objects; i++)

    {
        delete object_ptrs[i];
    }

    cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)

{
    for(int i = 0; i<num_persons; i++)
    {
        if(id == person_ptrs[i]->get_id())
          return person_ptrs[i];
    }
    cout << "ID not found" << endl;
    return NULL;
}

Gold_Mine* Model::get_Gold_Mine_ptr(int id)

{
    for(int i = 0; i<num_mines; i++)
    {
        if(id == mine_ptrs[i]->get_id())
           return mine_ptrs[i];
    }

    cout << "ID not found" << endl;
    return NULL;
}

Town_Hall* Model::get_Town_Hall_ptr(int id)

{
    for (int i = 0; i < num_halls; i++)

    {
        if (id == hall_ptrs[i]->get_id())
        return hall_ptrs[i];
    }

    cout << "ID not found" << endl;
    return NULL;
}

//returns boolean value depending whether update occured or not

bool Model::update()

{
    bool update = false;
    time++;

    for(int i = 0; i < num_objects; i++)

    {
        if(object_ptrs[i]->update())
        update = true;
    }

    return update;
}

//shows status of different objects in the game

void Model::show_status()

{
    cout << "Time: " << Model::time << endl;
    for (int i = 0; i < num_objects; i++)

    {
        object_ptrs[i]->show_status();
    }
}

//Used to plot the objects in the grid array
void Model::display(View& view)
{
  view.clear();

for(int i=0; i < num_persons; i++)
{
  if(person_ptrs[i]->is_alive())
  {
    view.plot((person_ptrs[i]));
  }
}


  view.plot((object_ptrs[2]));
	view.plot((object_ptrs[3]));
	view.plot((object_ptrs[4]));
  view.draw();

}
