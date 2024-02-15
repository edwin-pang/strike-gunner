#include <stdio.h>
#include <osbind.h>
#include "MODEL.H"
#include "TYPES.H"

int main()
{
    PlayerShip player;
    Bullet bullet;
    
    Position *player_pos = &(player.position);
    Position *bullet_pos = &(bullet.position);
    
    player.position.x = 320;
    player.position.y = 200;

    bullet.position.x = 320;
    bullet.position.y = 300;

    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /* testing for no collision */

    bullet.position.y = 232;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /* testing for bottom-up collision */

    bullet.position.y = 168;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /* testing for top-down collision */

    bullet.position.x = 288;
    bullet.position.y = 200;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /* testing for left-bound collision */

    bullet.position.x = 352;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));   /* testing for right-bound collision */



    bullet.position.x = 200;
    bullet.position.y = 200;
    player.position.x = 190;                                    /*test collision for bullet 1 y above ship*/
    player.position.y = 208;                                    
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));

    player.ver_dir = 1;
    move_player(&player);
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /*move player ship up 1 y and check collsion*/

    return 0;
}




/*
 printf("%d\n", bullet.position.x);
    printf("%d\n", bullet.position.y);
    printf("%d\n", player.position.x);
    printf("%d\n", player.position.y);

    */