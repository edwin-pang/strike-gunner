#include "MODEL.H"

/*The location for things is going to represent the top left corner of their bitmap*/
/*for now lets imagine that x = 0-50, and x = 590-640 are not inside the playable area (this is the side panel where health and stuff will be)*/
/*no ship cannot fly below y = 368*/
void init_playership(Model *model, int player){
    model->ship[player].position.x = 288;       /* initialize at bottom-middle of screen */
    model->ship[player].position.y = 368;
    model->ship[player].speed = 1;             /* arbitrary value for now, need to understand clock cycles more */
    model->ship[player].lives = 3;
    model->ship[player].wep_upgrade = 10;       /* was not sure how much damage player should start with */
    model->ship[player].fire_wep = 0;
    model->ship[player].fire_spec = 0;
    model->ship[player].collision = 0;
}

void move_player (PlayerShip *player) {
    Position *position = &(player->position);
    move_ship_pos(position, player->hor_dir, player->ver_dir, LEFT_BOUND_PLAYER,RIGHT_BOUND_PLAYER);
}

void move_ship_pos(Position *position, UINT8 hor_dir, UINT8 ver_dir, UINT16 left_bound, UINT16 right_bound){
    if (hor_dir == 1 && position->x < (right_bound - SHIP_WIDTH)){
            position->x += 1;    /*move player one to the right if that direction is inputted, and it still has room to move right*/
        }
        else if (hor_dir == 2 && position->x > (left_bound + 1)) {
         position->x -= 1;      /*move player one to the left if that direction is inputted, and it still has room to move left*/
        }
        /*seperate if because player can move both horizontally and vertically in one clock cycle*/
        if (ver_dir == 1 && position->y > 0) {
         position->y -= 1;      /*move player one pixel upwards if inputted, and it still has room to move up*/
        }
        else if (ver_dir == 2 && position->y <= 368) {
         position->y += 1;      /*move player one pixel downwards if inputted, and it still has room to move down*/
    }
}

void player_shoot (PlayerShip *player, PlayerBullet *bullets) {
    if (player->fire_wep == 1) {
        int i = 0;
        while (i < 49 && bullets[i].position.x != 0 ){
            i++;            /*find a bullet in the array not being used*/
        }
        bullets[i].position.y = player->position.y - 16;
        bullets[i].position.x = player->position.x;
    }
}

void init_helicopter(Model *model){
    int i;
    for(i = 0; i < 20; i++){
        model->helicopters[i].speed = 1;
        model->helicopters[i].fire_wep = 0;
        model->helicopters[i].cooldown = 210;
        model->helicopters[i].cur_weapon = 1;
        model->helicopters[i].collision = 0;
        model->helicopters[i].value = 100;
    }
}

void move_heli(Helicopter *helicopter){
    Position *heli_pos = &(helicopter->position);
    move_ship_pos(heli_pos, helicopter->hor_dir, helicopter->ver_dir, LEFT_BOUND_PLAYER, RIGHT_BOUND_PLAYER);
}

void move_heli_pos(Position *position, UINT8 hor_dir, UINT8 ver_dir, UINT16 left_bound, UINT16 right_bound){
    if (hor_dir == 1 && position->x < (right_bound - SHIP_WIDTH)){
            position->x += 1;           /*move helicopter one to the right if that direction is inputted, and it still has room to move right*/
        }
        else if (hor_dir == 2 && position->x > (left_bound + 1)) {
            position->x -= 1;           /*move helicopter one to the left if that direction is inputted, and it still has room to move left*/
        }
                                        /*seperate if because helicopter can move both horizontally and vertically in one clock cycle*/
        if (ver_dir == 1 && position->y > 0) {
            position->y -= 1;           /*move helicopter one pixel upwards if inputted, and it still has room to move up*/
        }
        else if (ver_dir == 2 && position->y <= 368) {
            position->y += 1;           /*move helicopter one pixel downwards if inputted, and it still has room to move down*/
    }
}

void init_jet(Model *model){
    int i;
    for(i = 0; i < 20; i++){
        model->jets[i].speed = 1;
        model->jets[i].fire_wep = 0;
        model->jets[i].cooldown = 210;
        model->jets[i].cur_weapon = 2;
        model->jets[i].collision = 0;
        model->jets[i].value = 200;
    }
}

void move_jet(Jet *jet){
    Position *jet_pos = &(jet->position);
    move_jet_pos(jet_pos, jet->hor_dir, jet->ver_dir, LEFT_BOUND_PLAYER, RIGHT_BOUND_PLAYER);
}

void move_jet_pos(Position *position, UINT8 hor_dir, UINT8 ver_dir, UINT16 left_bound, UINT16 right_bound){
    if (hor_dir == 1 && position->x < (right_bound - SHIP_WIDTH)){
            position->x += 1;           /*move jet one to the right if that direction is inputted, and it still has room to move right*/
        }
        else if (hor_dir == 2 && position->x > (left_bound + 1)) {
            position->x -= 1;           /*move jet one to the left if that direction is inputted, and it still has room to move left*/
        }
                                        /*seperate if because jet can move both horizontally and vertically in one clock cycle*/
        if (ver_dir == 1 && position->y > 0) {
            position->y -= 1;           /*move jet one pixel upwards if inputted, and it still has room to move up*/
        }
        else if (ver_dir == 2 && position->y <= 368) {
            position->y += 1;           /*move jet one pixel downwards if inputted, and it still has room to move down*/    
    }
}

void init_score(Model *model){
    model->score.total = 0;
    model->score.position.x = 5;
    model->score.position.y = 180;
    model->score.x_len = 40;                            /* a box for now, can change later if need be */
    model->score.y_len = 40;
}

void update_score(Model *model, int value){
    model->score.total += value;
}

void init_life_counter(Model *model){
    model->lives.health_bar = 3;
    model->lives.position.x = 5;
    model->lives.position.y = 230;
    model->lives.x_len = 40;
    model->lives.y_len = 40;
}

void update_lives(Model *model){
    model->lives.health_bar = model->ship->lives;       /* displayed lives decreases as player's lives decrease*/
}

void init_enem_bullets(Model *model){
    int i;
    for(i = 0; i < 50; i++){
        model->bullets[i].speed = 1;
        model->bullets[i].damage = 10;                  /* does amount of damage really matter? everything 1-shots the player if I remember correctly */
    }
}

void move_enem_bullet(Bullet *bullet){
    bullet->position.y += bullet->speed;                /* seems okay, can be changed in the future*/
}

void init_player_bullets(Model *model){
    int i;
    for(i = 0; i < 50; i++){
        model->playerBullets[i].speed = 1;
        model->playerBullets[i].damage = 20;
    }
}

void move_player_bullet(PlayerBullet *playerBullet){
    playerBullet->position.y -= playerBullet->speed;
}

void init_missile(Model *model){
    int i;
    for(i = 0; i < 25; i++){
        model->missiles[i].speed = 1;
        model->missiles[i].damage = 20;
        model->missiles[i].home_cd = 300; 
    }
}

void move_player_missile(Missile *missile){
    missile->position.y += missile->speed;
}

int check_collision(Position *pos1, UINT8 width1, UINT8 height1, Position *pos2, UINT8 width2, UINT8 height2){
    int obj1_left = pos1->x;
    int obj1_right = pos1->x + width1 - 1;
    int obj1_top = pos1->y;
    int obj1_bottom = pos1->y + height1 - 1;

    int obj2_left = pos2->x;
    int obj2_right = pos2->x + width2 - 1;
    int obj2_top = pos2->y;
    int obj2_bottom = pos2->y + height2 - 1;

    if (obj1_right >= obj2_left && obj1_left <= obj2_right && obj1_bottom >= obj2_top && obj1_top <= obj2_bottom){  /* this checks for top-down and bottom-up collisions */
        return 1;
    }

    return 0;
}
void heli_shoot(Helicopter *helicopter, Bullet *bullets){
    int i = 0;
    int j = 0;
    int bullet_x = helicopter->position.x;
    int bullet_y = helicopter->position.y + 32;
    while (i < 3 && j < 49){
        while (j < 49 && bullets[i].position.x < 2) {
            j++;
        }
        bullets[i].position.x = bullet_x;  
        bullets[i].position.y = bullet_y;
            bullet_x += 12;
            i++;
    }
        helicopter->cooldown = 300;
    }

