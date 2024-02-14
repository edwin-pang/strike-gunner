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

    printf("%d\n", check_collision(player_pos, bullet_pos));    /* testing for no collision */

    bullet.position.y = 232;
    printf("%d\n", check_collision(player_pos, bullet_pos));    /* testing for bottom-up collision */

    bullet.position.y = 168;
    printf("%d\n", check_collision(player_pos, bullet_pos));    /* testing for top-down collision */

    bullet.position.x = 288;
    bullet.position.y = 200;
    printf("%d\n", check_collision(player_pos, bullet_pos));    /* testing for left-bound collision */

    bullet.position.x = 352;
    printf("%d\n", check_collision(player_pos, bullet_pos));    /* testing for right-bound collision */

    return 0;
}