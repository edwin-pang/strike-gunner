#include "EVENTS.H"

void on_playership_move(Model *model, int player){
  switch (model->ship[player].hor_dir)
  {
  case 1:
    /* move right */
    break;

  case 2:
    /* move left */
    break;
  }

  switch (model->ship[player].ver_dir)
  {
  case 1:
    /* move up */
    break;
  
  case 2:
    /* move down */
    break;
  }
}

void move_up_cancel(PlayerShip *player){
  
}


















/*
  while (check_collision(*bullet->position, *Uh Oh->position) != 1){       /* not too sure if this will work, just general idea */
  /*      move_bullet(*bullet);
    }*/

