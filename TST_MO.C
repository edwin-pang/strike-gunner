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

    Helicopter heli;
    Position *heli_pos = &(heli.position);
    
                                                               
    bullet.position.x = 200;
    bullet.position.y = 200;                                                                                          /* 1 = collision, 0 = no collision */
    player.position.x = 190;
    player.position.y = 208;                                    
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /* test collision for bullet 1 y above ship */

    player.ver_dir = 1;
    move_player(&player);
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));    /* move player ship up 1 y and check collision */

    player.ver_dir = 0;
    player.position.x = 168;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));
    player.hor_dir = 1;
    move_player(&player);
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));     /* move player ship right 1 x and check collision */

    player.position.x = 208;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));
    player.hor_dir = 2;
    move_player(&player);
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));     /* move player ship left 1 x and check collision */

    player.position.x = 200;
    player.position.y = 168;
    player.hor_dir = 0;
    player.ver_dir = 2;
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));
    move_player(&player);
    printf("%d\n", check_collision(player_pos, SHIP_WIDTH, SHIP_HEIGHT, bullet_pos, BULLET_WIDTH, BULLET_HEIGHT));     /* move player ship down 1 y and check collision */

    heli.position.x = 300;
    heli.position.y = 300;
    heli.hor_dir = 1;
    move_heli(&heli);
    printf("%d\n", heli.position.x);
    heli.hor_dir = 2;
    move_heli(&heli);
    printf("%d\n", heli.position.x);
    heli.hor_dir = 0;
    heli.ver_dir = 1;
    move_heli(&heli);
    printf("%d\n", heli.position.y);
    heli.ver_dir = 2;
    move_heli(&heli);
    printf("%d\n", heli.position.y);

    return 0;
}




/*
 printf("%d\n", bullet.position.x);
    printf("%d\n", bullet.position.y);
    printf("%d\n", player.position.x);
    printf("%d\n", player.position.y);

    */