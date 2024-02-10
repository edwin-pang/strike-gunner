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

    while (check_collision(*bullet->position, *Uh Oh->position) != 1){       /* not too sure if this will work, just general idea */
        move_bullet(*bullet);
    }

}

void move_bullet(Bullet *bullet){
    bullet->position->y += bullet->speed;             /* this doesnt seem right, i think bullet speed should be declared a constant somewhere idk tho*/
}

int check_collision(Position *pos1, Position *pos2){    /* I think i found the general collsion function we need!! */
    int obj1_left = pos1->x;
    int obj1_right = pos1->x + 32;        // I think there should also be way to pass in the bitmap width and height but for now hard coded
    int obj1_top = pos1->y;
    int obj1_bottom = pos1->y + 32;

    int obj2_left = pos2->x;
    int obj2_right = pos2->x + 32;
    int obj2_top = pos2->y;
    int obj2_bottom = pos2->y + 32;

    if (obj1_right >= obj2_left && obj1_left <= obj2_right && obj1_bottom >= obj2_top) // this checks for collisions top-down
    {
        return 1;
    }

    if (obj1_right >= obj2_left && obj1_left <= obj2_right && obj1_top >= obj2_bottom) // this checks for collisions bottom-up
    {
        return 1;                                                                      // I would've just thrown an OR operator into code above but
                                                                                       // if im writing the function like this, it depends what obj1 and obj2 are.
    }

    return 0;
}
