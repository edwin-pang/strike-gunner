#ifndef EVENTS_H
#define EVENTS_H
#include "MODEL.H"
#include "TYPES.H"

#define quit
void on_playership_move(Model *model, int player);
void move_up_request(PlayerShip *player);
void move_up_cancel(PlayerShip *player);
void move_down_request(PlayerShip *player);
void move_down_cancel(PlayerShip *player);
void move_right_request(PlayerShip *player);
void move_right_cancel(PlayerShip *player);
void move_left_request(PlayerShip *player);
void move_left_cancel(PlayerShip *player);
void fire_main_request(PlayerShip *player);
void fire_main_cancel(PlayerShip *player);
void fire_spec_request(PlayerShip *player);
void fire_spec_cancel(PlayerShip *player);
void quit_game(Model *model);


#endif