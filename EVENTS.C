#include "EVENTS.H"

void on_playership_move(Model *model, int player){
  PlayerShip *curr_ship = &(model->ship[player]);

  switch (curr_ship->hor_dir)
  {
  case RIGHT_KEY:                                 /* not too sure how hardware inputs work yet*/
    /* move right calling move_player */          /* just assigned each "key" to a number in TYPES.H*/
    move_player(curr_ship);
    break;

  case LEFT_KEY:
    /* move left calling move_player*/
    move_player(curr_ship);
    break;
  }

  switch (curr_ship->ver_dir)
  {
  case UP_KEY:
    /* move up calling move_player*/
    move_player(curr_ship);
    break;
  
  case DOWN_KEY:
    /* move down calling move_player*/
    move_player(curr_ship);
    break;
  }
}

void move_up_cancel(PlayerShip *player){
  
}


















/*
  while (check_collision(*bullet->position, *Uh Oh->position) != 1){       /* not too sure if this will work, just general idea */
  /*      move_bullet(*bullet);
    }*/

