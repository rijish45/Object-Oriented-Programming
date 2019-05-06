/* Created by Rijish Ganguly
   for EC 327, Fall of 2016
   U65638769
*/

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Model.h"
#include "View.h"
#include "Soldier.h"


void do_new_command(Model&, char, int, double, double);
void do_list_command(Model&, View&);
void do_move_command(Model&, View&, int, double, double);
void do_work_command(Model&, View&, int, int, int);
void do_stop_command(Model&, View&, int);
bool do_go_command(Model&, View&);
void do_run_command(Model&, View&);
void do_attack_command(Model&, int, int);


#endif
