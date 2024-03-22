#include "random.h"
#include "MODEL.H"
#include "STRIKE.H"
void random_formation(UINT32 seed){
    UINT32 random = seed % FORMATIONS;
    Enemy *enemies = model.enemies;
    if(random == 0){
        formation1(enemies);
    }



}



void formation1(Enemy *enemies){
    int i = 0;
    int end = 0;
    int spawned = 0;
    int x = 150;
    int y = -10;
    while (i < NUM_ENEMY && !end){
        if (enemies[i].position.x < 2 && spawned < 3){
            enemies[i].position.y = y;
            enemies[i].position.x = x;
            enemies[i].ver_dir = -1;
            x += 60;
            spawned++;
        }
        if(spawned == 3)
            end = 1;
        i++;
    }
}