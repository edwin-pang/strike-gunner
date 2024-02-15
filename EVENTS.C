#include "EVENTS.H"

void on_playership_move(Model *model, int player){
  switch (model->ship[player].hor_dir)
  {
  case RIGHT_KEY:
    /* move right calling move_player */
    break;

  case LEFT_KEY:
    /* move left calling move_player*/
    break;
  }

  switch (model->ship[player].ver_dir)
  {
  case UP_KEY:
    /* move up calling move_player*/
    break;
  
  case DOWN_KEY:
    /* move down calling move_player*/
    break;
  }
}

void move_up_cancel(PlayerShip *player){
  
}


















/*
  while (check_collision(*bullet->position, *Uh Oh->position) != 1){       /* not too sure if this will work, just general idea */
  /*      move_bullet(*bullet);
    }*/

