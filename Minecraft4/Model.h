/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/


#ifndef MODEL_H
#define MODEL_H
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Person.h"
#include "View.h"
#include "Soldier.h"
#include <list>


class Model

{

public:

    Model();
    ~Model();

    void handle_new_command(char, int, double, double);
    Person* get_Person_ptr(int id);
    Gold_Mine* get_Gold_Mine_ptr(int id);
    Town_Hall* get_Town_Hall_ptr(int id);
    bool update();
    void display(View&);
    void show_status();

private:

    int time;

    list<Game_Object*> object_ptrs;
    list<Game_Object*> active_ptrs;
    list<Person*> person_ptrs;
    list<Gold_Mine*> mine_ptrs;
    list<Town_Hall*> hall_ptrs;

    //Game_Object* object_ptrs[10];
    //int num_objects;
    //Person* person_ptrs[10];
    //int num_persons;
    //Gold_Mine* mine_ptrs[10];
    //int num_mines;
    //Town_Hall* hall_ptrs[10];
    //int num_halls;
  Model(const Model &obj);

  list<Game_Object*>::iterator object_iter;
	list<Game_Object*>::iterator active_iter;
	list<Person*>::iterator person_iter;
	list<Gold_Mine*>::iterator mine_iter;
	list<Town_Hall*>::iterator hall_iter;


};

#endif
