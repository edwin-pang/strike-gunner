#ifndef EVENTS_H
#define EVENTS_H
#include "MODEL.H"
#include "TYPES.H"

void on_playership_move(Model *model, int player);
void move_up_cancel(PlayerShip *player);

#endif