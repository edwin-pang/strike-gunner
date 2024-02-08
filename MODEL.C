#include "MODEL.H"

/*The location for things is going to represent the top left corner of their bitmap*/
/*for now lets imagine that x = 0-50, and x = 590-640 are not inside the playable area (this is the side panel where health and stuff will be)*/
/*no ship cannot fly below y = 368*/
#define LEFT_BOUND   50
#define RIGHT_BOUND  590
#define PLAYER_WIDTH 32
void move_player (PlayerShip player) {
    if (player.hor_dir == 1 && player.x < (RIGHT_BOUND - PLAYER_WIDTH)){
        player.x += 1;      /*move player one to the right if that direction is inputted, and it still has room to move right*/
    }
    else if (player.hor_dir == 2 && player.x > (RIGHT_BOUND + 1)) {
        player.x -= 1;      /*move player one to the left if that direction is inputted, and it still has room to move left*/
    }
    /*seperate if because player can move both horizontally and vertically in one clock cycle*/
    if (player.vertical == 1 && player.y > 0) {
        player.y += 1;      /*move player one pixel upwards if inputted, and it still has room to move up*/
    }
    else if (player.vertical == 2 && player.y <= 368) {
        player.y -= 1;      /*move player one pixel downwards if inputted, and it still has room to move down*/
    }
}

void player_shoot (PlayerShip player) {
    if (player_shoot == 1) {
        
    }
}