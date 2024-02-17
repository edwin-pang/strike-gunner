#include "events.h"
#include "model.h"
#include "TYPES.H"
#include <stdio.h>
#include <osbind.h>
int main() {

    Model *model;
    int key;
    int collision;

    PlayerShip *player = &(model->ship[PLAYER_ONE]);
    Bullet *bullet = &(model->bullets[0]);

    Position *player_pos = &(player->position);
    Position *bullet_pos = &(bullet->position);

    /* INITIALIZING POSITIONS OF PLAYER AND BULLET */

    init_playership(model, PLAYER_ONE); /* Player starts at (288, 368)*/

    bullet_pos->x = 320;
    bullet_pos->y = 190;

    while(1){

        /* Loop for continuous keyboard inputs */
        if(cconis())
        {
            key = cconis();

            if(key == UP_KEY){
                move_up_request(&player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);

            }
            else if(key == DOWN_KEY){
                move_down_request(&player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if(key == RIGHT_KEY){
                move_right_request(&player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if(key == LEFT_KEY){
                move_left_request(&player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if (key == ESC_KEY){
                break;
            }
        }

        collision = check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT);
        printf("Collision: %d\n", collision);
    }

    return 0;
}