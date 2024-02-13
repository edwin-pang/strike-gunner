#include <osbind.h>
#include "model.h"
#include "TYPES.H"

int main()
{
    PlayerShip player;
    Bullet bullet;

    player.position.x = 320;
    player.position.y = 200;

    bullet.position.x = 320;
    bullet.position.y = 300;

    printf(check_collision(*player.position, *bullet.position));

    bullet.position.x = 320;
    bullet.position.y = 230;

    printf(check_collision(*player.position, *bullet.position));
}