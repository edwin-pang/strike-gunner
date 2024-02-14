#include <stdio.h>
#include <osbind.h>
#include "MODEL.H"
#include "TYPES.H"

int main()
{
    PlayerShip player;
    Bullet bullet;
    Position *player1 = &(player.position);
    Position *bullet1 = &(bullet.position);
    
    player.position.x = 320;
    player.position.y = 200;

    bullet.position.x = 320;
    bullet.position.y = 300;

    printf("%d\n", check_collision(player1, bullet1));

    bullet.position.x = 320;
    bullet.position.y = 230;

    printf("%d\n", check_collision(player1,bullet1));

    return 0;
}