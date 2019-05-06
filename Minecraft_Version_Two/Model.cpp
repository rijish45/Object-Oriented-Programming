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
#include "Input_Handling.h"
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



    person_ptrs.push_back(new Miner(1, miner1loc));
    person_ptrs.push_back(new Miner(2, miner2loc));
    person_ptrs.push_back(new Soldier(3, soldier1loc));
    person_ptrs.push_back(new Soldier(4, soldier2loc));


    mine_ptrs.push_back(new Gold_Mine(1, mine1loc));
    mine_ptrs.push_back(new Gold_Mine(2, mine2loc));
    hall_ptrs.push_back(new Town_Hall(1, hallloc));

//Add Persons to object_pts

for(person_iter = person_ptrs.begin(); person_iter != person_ptrs.end(); person_iter++)

{

   object_ptrs.push_back(dynamic_cast<Game_Object*>(*person_iter));

}

//Add Gold Mines to object_ptrs

for (mine_iter = mine_ptrs.begin(); mine_iter != mine_ptrs.end(); mine_iter++)

  {

    object_ptrs.push_back(dynamic_cast<Game_Object*>(*mine_iter));

  }


object_ptrs.push_back(dynamic_cast<Game_Object*>(hall_ptrs.front()));
active_ptrs = object_ptrs;




cout  << "Model default constructed." << endl;






}


//destroys all game objects

Model::~Model()

{
    for(object_iter = object_ptrs.begin(); object_iter != object_ptrs.end(); object_iter++)

    {
        delete *object_iter;
    }

    cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)

{
    person_iter = person_ptrs.begin();

    for(int j = 0; j < person_ptrs.size(); j++)
    {
        if(id == (*person_iter)->get_id())
          return *person_iter;
        person_iter++;
    }

   return 0;
}

Gold_Mine* Model::get_Gold_Mine_ptr(int id)

{
    mine_iter = mine_ptrs.begin();
    for(int i = 0; i < mine_ptrs.size(); i++)
    {
        if(id == (*mine_iter)->get_id())
           return *mine_iter;
        mine_iter++;
    }

    return 0;
}

Town_Hall* Model::get_Town_Hall_ptr(int id)

{
    hall_iter = hall_ptrs.begin();

    for (int i = 0; i < hall_ptrs.size(); i++)


    {
        if (id == (*hall_iter)->get_id())
        return *hall_iter;
      hall_iter++;
    }

    return 0;
}



void Model::handle_new_command(char type, int id, double x, double y)
{
	if (id < 0)

    throw Invalid_Input("ID must be greater than zero.");

	switch (type)

  {
		case 'g':
		{

			Gold_Mine *ptr = get_Gold_Mine_ptr(id);
      if (ptr != 0) // id found, object already exists

        throw Invalid_Input("Gold_Mine with ID already exists.");

      Cart_Point destination = Cart_Point(x,y);
			mine_ptrs.push_back(new Gold_Mine(id,destination));
			object_ptrs.push_back(dynamic_cast<Game_Object*>(mine_ptrs.back()));
			active_ptrs.push_back(dynamic_cast<Game_Object*>(mine_ptrs.back()));
			break;

    }

		case 't':
		{
			Town_Hall *ptr = get_Town_Hall_ptr(id);

      if (ptr != 0)

        throw Invalid_Input("Town_Hall with ID already exists.");


      Cart_Point destination = Cart_Point(x,y);
			hall_ptrs.push_back(new Town_Hall(id,destination));
			object_ptrs.push_back(dynamic_cast<Game_Object*>(hall_ptrs.back()));
			active_ptrs.push_back(dynamic_cast<Game_Object*>(hall_ptrs.back()));
			break;

		}

    case 'm':
		{
			Person *ptr = get_Person_ptr(id);

      if (ptr != 0)
				throw Invalid_Input("Person with ID already exists.");

      Cart_Point destination = Cart_Point(x,y);
			person_ptrs.push_back(new Miner(id,destination));
			object_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
			active_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
			break;

    }

    case 's':
		{
			Person *ptr = get_Person_ptr(id);
			if (ptr != 0)
				throw Invalid_Input("Person with ID already exists.");

			person_ptrs.push_back(new Soldier(id,Cart_Point(x,y)));
			object_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
			active_ptrs.push_back(dynamic_cast<Game_Object*>(person_ptrs.back()));
			break;
		}
    default:
			throw Invalid_Input("Incorrect object type specified.");
	}
}



//returns boolean value depending whether update occured or not

bool Model::update()

{

    time++;
    int events = 0;

  for (active_iter = active_ptrs.begin(); active_iter != active_ptrs.end(); active_iter++)

  {
		bool update;

    update = (*active_iter)->update();

		if (update)
			events++;

  }


	for (active_iter = active_ptrs.begin(); active_iter != active_ptrs.end(); active_iter++)
	{
		if (!(*active_iter)->is_alive())
		{
			active_ptrs.erase(active_iter);
      cout << "Dead object removed " << endl;
		}
	}

	if (events > 0)
		return true;
	else
		return false;
}


//shows status of different objects in the game

void Model::show_status()

{
    cout << "Time: " << Model::time << endl;

    for (object_iter = object_ptrs.begin(); object_iter != object_ptrs.end(); object_iter++)

  {
		(*object_iter)->show_status();
	}


}

//Used to plot the objects in the grid array
void Model::display(View& view)
{
  view.clear();

for(active_iter = active_ptrs.begin(); active_iter!= active_ptrs.end(); active_iter++)

{

    view.plot(*active_iter);


}


  //view.plot((object_ptrs[2]));
	//view.plot((object_ptrs[3]));
	//view.plot((object_ptrs[4]));
  view.draw();

}
