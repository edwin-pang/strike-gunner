#include "MODEL.H"

/*The location for things is going to represent the top left corner of their bitmap*/
/*for now lets imagine that x = 0-50, and x = 590-640 are not inside the playable area (this is the side panel where health and stuff will be)*/
/*no ship cannot fly below y = 368*/
UINT32 player_bullet_hex[16] = 
{
    0x00700E00,
    0x00700E00,
    0x00700E00,
    0x00700E00,
    0x00700E00,
    0x00700E00,
    0x00700E00,
    0x3800001C,
    0x3800001C,
    0x3800001C,
    0x3800001C,
    0x3800001C,
    0x3800001C,
    0x3800001C,
    0x00000000,
    0x00000000
};

void move_player (PlayerShip player) {
    if (player.hor_dir == 1 && player.position.x < (RIGHT_BOUND - PLAYER_WIDTH)){
        player.position.x += 1;      /*move player one to the right if that direction is inputted, and it still has room to move right*/
    }
    else if (player.hor_dir == 2 && player.position.x > (RIGHT_BOUND + 1)) {
        player.position.x -= 1;      /*move player one to the left if that direction is inputted, and it still has room to move left*/
    }
    /*seperate if because player can move both horizontally and vertically in one clock cycle*/
    if (player.ver_dir == 1 && player.position.y > 0) {
        player.position.y += 1;      /*move player one pixel upwards if inputted, and it still has room to move up*/
    }
    else if (player.ver_dir == 2 && player.position.y <= 368) {
        player.position.y -= 1;      /*move player one pixel downwards if inputted, and it still has room to move down*/
    }
}


void player_shoot (PlayerShip player, Model model) {
    if (player.fire_wep == 1) {
        int i = 0;
        while ((model.PlayerBullets[i]).position.y != 0 ){
            i++;            /*find a bullet in the array not being used*/
        }
        (model.PlayerBullets[i]).position.y = player.position.y + 16;
    }
}

void move_bullet(Bullet *bullet){
    bullet->position.y += bullet->speed;             /* seems okay, can be changed in the future*/
}

int check_collision(Position *pos1, Position *pos2){    /* I think i found the general collsion function we need!! */
    int obj1_left = pos1->x;
    int obj1_right = pos1->x + 32;                      /* I think there should also be way to pass in the bitmap width and height but for now hard coded*/
    int obj1_top = pos1->y;
    int obj1_bottom = pos1->y + 32;

    int obj2_left = pos2->x;
    int obj2_right = pos2->x + 32;
    int obj2_top = pos2->y;
    int obj2_bottom = pos2->y + 32;

    if (obj1_right >= obj2_left && obj1_left <= obj2_right && obj1_bottom >= obj2_top){  /*this checks for collisions top-down*/
        return 1;
    }

    if (obj1_right >= obj2_left && obj1_left <= obj2_right && obj1_top >= obj2_bottom){  /*this checks for collisions bottom-up*/
        return 1;                                                                        /*I would've just thrown an OR operator into code above but*/
    }      
                                                                                         /*if im writing the function like this, it depends what obj1 and obj2 are*/
    return 0;
}

void update_score(Score *score, int value){
    score->value += value;
}

void move_heli_down(Helicopter *helicopter){                                            /* I think this belongs in events.c (timer based)*/
    if(helicopter->ver_dir == 1 && helicopter->position.y < 368) {                      /* this is basically just the player ship code*/
        helicopter->position.y += helicopter->speed;
    }
}