#include "MODEL.H"

/*The location for things is going to represent the top left corner of their bitmap*/
/*for now lets imagine that x = 0-50, and x = 590-640 are not inside the playable area (this is the side panel where health and stuff will be)*/
/*no ship cannot fly below y = 368*/

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

    while (check_collision(bullet) != 1){       /* not too sure if this will work, just general idea */
        move_bullet(*bullet);
    }

}

void move_bullet(Bullet *bullet){
    bullet->y += bullet->speed;         /* this doesnt seem right, i think bullet speed should be declared a constant somewhere idk tho*/
}

int check_collision(Bullet bullet){    /* i feel like there should be a general function to check for collisions but i think thats what we were */
    int bulletLeft = bullet.x;         /*sorta dicussing earlier with having to check for all collisions all the time*/
    int bulletRight = bullet.x + 32;
    int bulletTop = bullet.y;
    int bulletBottom = bullet.y + 32;
    
    // There should be a way to also pass other types of structs for collsions but i'm not too sure how

    if (bulletRight >= objectLeft && bulletLeft <= objectRight && bulletBottom >= objectTop){ // checks right bound of bullet
        return 1;
    }
    
    return 0;
}
