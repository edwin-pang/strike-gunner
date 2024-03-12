#include "events.h"
#include "model.h"
#include "TYPES.H"
#include <stdio.h>
#include <osbind.h>
#include "EFFECTS.H"
int main() {

    Model model;
    Model *model_ptr = &model;

    int key;
    int collision;
    int collision2;

    PlayerShip *player = &(model_ptr->ship[PLAYER_ONE]);
    Helicopter *heli = &(model_ptr->helicopters[0]);
    Bullet *bullet = &(model_ptr->bullets[0]);
    PlayerBullet *p_bullet = &(model_ptr->playerBullets[0]);

    Position *player_pos = &(player->position);
    Position *heli_pos = &(heli->position);
    Position *bullet_pos = &(bullet->position);
    Position *p_bullet_pos = &(p_bullet->position);


    /* INITIALIZING POSITIONS OF PLAYER AND BULLET */

    init_playership(model_ptr, PLAYER_ONE); /* Player starts at (288, 368)*/
    init_player_bullets(model_ptr);

    bullet_pos->x = 288;
    bullet_pos->y = 340;

    heli_pos->x = 288;
    heli_pos->y = 300;

    printf("USE WASD KEYS TO MOVE AND X TO SHOOT AT THE START AND USE ESC TO EXIT.\n\n");
    printf("NOTE: THERE IS AN ERROR WHERE BULLET \nMOVES WHEN NOT FIRED ON FIRST ITERATION OF LOOP.\n\n");
    printf("ALSO: TO CHECK FOR COLLISION BETWEEN PLAYER AND ENEMY BULLET MOVE UP \nUNTIL PLAYER Y REACHES 347.\n\n");
    printf("ALSO: TO CHECK FOR COLLISION BETWEEN PLAYER BULLET AND ENEMY HELICOPTER PRESS ANY KEY TO KEEP ITERATING THROUGH LOOP.\n");

    while(TRUE){
        key = Cnecin();
        /* Loop for continuous keyboard inputs */

        if(key)
        {
            if(key == 'w'){
                move_up_request(player);
                move_player(player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if(key == 's'){
                move_down_request(player);
                move_player(player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if(key == 'a'){
                move_left_request(player);
                move_player(player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if(key == 'd'){
                move_right_request(player);
                move_player(player);
                printf("Player is x: %d, y: %d\n", player_pos->x, player_pos->y);
            }
            else if(key == 'x'){
                fire_main_request(player);
            }
            else if (key == ESC_KEY){
                break;
            }
        }

        move_down_cancel(player);
        move_up_cancel(player);
        move_left_cancel(player);
        move_right_cancel(player);
        player_shoot(player, model_ptr->playerBullets);
        move_bullets(model_ptr->playerBullets,model_ptr->bullets);
        printf("Player bullet is x: %d, y: %d\n", p_bullet_pos->x, p_bullet_pos->y);
        collision = check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT);
        collision2 = check_collision(p_bullet_pos, PLAYER_BULLET_WIDTH, PLAYER_BULLET_HEIGHT, heli_pos, SHIP_WIDTH, SHIP_HEIGHT);
        printf("Collision between player and enemy bullet: %d\n", collision);
        printf("Collision between player bullet and enemy helicopter: %d\n\n", collision2);
    }

    return 0;
}