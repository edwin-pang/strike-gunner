#include "MODEL.H"

/*The location for things is going to represent the top left corner of their bitmap*/
/*for now lets imagine that x = 0-50, and x = 590-640 are not inside the playable area (this is the side panel where health and stuff will be)*/
/*no ship cannot fly below y = 368*/

void init_playership(Model *model, int player){
    model->ship[player].position.x = 288;       /* initialize at bottom-middle of screen */
    model->ship[player].position.y = 368;
    model->ship[player].speed = 2;             /* arbitrary value for now, need to understand clock cycles more */
    model->ship[player].lives = 3;
    model->ship[player].wep_upgrade = 10;       /* was not sure how much damage player should start with */
    model->ship[player].fire_wep = 0;
    model->ship[player].fire_spec = 0;
    model->ship[player].collision = 0;
    model->ship[player].death_time = 0;
}


void move_player (PlayerShip *player) {
    Position *position = &(player->position);
    move_ship_pos(position, player->hor_dir, player->ver_dir, player->speed, LEFT_BOUND_PLAYER,RIGHT_BOUND_PLAYER);
}

void move_ship_pos(Position *position, char hor_dir, char ver_dir, UINT8 speed, UINT16 left_bound, UINT16 right_bound){
    if (hor_dir == RIGHT && position->x < (right_bound - SHIP_WIDTH)){
            position->x += speed;    /*move player one to the right if that direction is inputted, and it still has room to move right*/
        }
        else if (hor_dir == LEFT && position->x > (left_bound + 1)) {
         position->x -= speed;      /*move player one to the left if that direction is inputted, and it still has room to move left*/
        }
        /*seperate if because player can move both horizontally and vertically in one clock cycle*/
        if (ver_dir == UP && position->y > 0) {
         position->y -= speed;      /*move player one pixel upwards if inputted, and it still has room to move up*/
        }
        else if (ver_dir == DOWN && position->y <= 368) {
         position->y += speed;      /*move player one pixel downwards if inputted, and it still has room to move down*/
    }
}

void init_enemy(Model *model){
    int i;
    for(i = 0; i < 20; i++){
        if(i % 2 == 0){
            model->enemies[i].speed = 1;
            model->enemies[i].cur_weapon = 1;
            model->enemies[i].type = 1;
            model->enemies[i].value = 100;
        }
        else{
            model->enemies[i].speed = 2;
            model->enemies[i].cur_weapon = 2;
            model->enemies[i].type = 2;
            model->enemies[i].value = 150;
        }
        model->enemies[i].position.x = 0;
        model->enemies[i].position.y = 0;
        model->enemies[i].fire_wep = 0;
        model->enemies[i].cooldown = 210;
        model->enemies[i].collision = 0;
    }
}


void move_enemy(Enemy *enemy){
    Position *heli_pos = &(enemy->position);
    move_ship_pos(heli_pos, enemy->hor_dir, enemy->ver_dir, enemy->speed, LEFT_BOUND_ENEMY_MOVEMENT, RIGHT_BOUND_ENEMY_MOVEMENT);
}




void init_score(Model *model){
    model->score.total = 0;
    model->score.position.x = 5;
    model->score.position.y = 180;
    model->score.x_len = 40;                            /* a box for now, can change later if need be */
    model->score.y_len = 40;
}

Score get_score(Model *model){
    return (model->score);
}
LifeCounter get_life(Model *model){
    return (model->lives);
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
        model->bullets[i].position.x = 0;
        model->bullets[i].position.y = 0;
        model->bullets[i].speed = 1;
        model->bullets[i].damage = 10;     
        model->bullets[i].num = i;           
        model->bullets[i].collision = 0;
    }
}

void move_enem_bullet(Bullet *bullet){
    bullet->position.y += bullet->speed;              
    if (bullet->hor_dir != 0)  
        bullet->position.x += (bullet->speed * bullet->hor_dir);
}


void init_player_bullets(Model *model){
    int i;
    for(i = 0; i < 50; i++){
        model->playerBullets[i].position.x = 0;
        model->playerBullets[i].position.y = 0;
        model->playerBullets[i].speed = 2;
        model->playerBullets[i].damage = 20;
        model->playerBullets[i].num = i;
        model->playerBullets[i].collision = 0;
    }
}

void move_player_bullet(PlayerBullet *playerBullet){
    playerBullet->position.y -= playerBullet->speed;
}

void init_missile(Model *model){
    int i;
    for(i = 0; i < 25; i++){
        model->missiles[i].position.x = 0;
        model->missiles[i].position.y = 0;
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
                                                /*establish the bounding box*/
    int obj2_left = pos2->x;
    int obj2_right = pos2->x + width2 - 1;
    int obj2_top = pos2->y;
    int obj2_bottom = pos2->y + height2 - 1;
                                            
    if (obj1_right >= obj2_left && obj1_left <= obj2_right && obj1_bottom >= obj2_top && obj1_top <= obj2_bottom){ 
        return 1;                               /*if objects have intersecting bounding boxes, return a 1*/
    }

    return 0;                                   /*else return a 0*/
}


void despawn_player_bullet(PlayerBullet *bullet){
    bullet->position.x = 1;            /*reset the bullet to resting state, however now using x = 1*/
    bullet->position.y = 0;            /*as a value indicating previously used bullet*/
    bullet->collision = 0;
    bullet->prev_x = 0;
    bullet->prev_y = 0;
}

void despawn_enem_bullet(Bullet *bullet){
    bullet->position.x = 1;            /*reset the bullet to resting state, however now using x = 1*/
    bullet->position.y = 0;            /*as a value indicating previously used bullet*/
}

void despawn_enemy(Enemy *enemy){
    enemy->position.x = 1;            /*reset the helicopter to resting state, however now using x = 1*/
    enemy->position.y = 0;            /*as a value indicating previously used helicopter*/
    enemy->collision = 0;
    enemy->death_time = 0;
}

void respawn_player(PlayerShip *player){
    if(player->lives > 0){
        player->death_time = 0;
        player->collision = 0;
        player->fire_wep = 0;
        player->wep_upgrade = 10;
        player->lives--;
        player->position.x = 288;
        player->position.y = 368;
    }
    else {
        
    }
}

void init_model(Model *model){
    init_playership(model,0);
    model->ship[1].position.x = 0;
    init_enem_bullets(model);
    init_player_bullets(model);
    init_missile(model);
    init_enemy(model);
    init_score(model);
    init_life_counter(model);
    model->quit_game = 0;
    model->game_over = 0;
    model->shot_time = 0;
}

void process_player(Model *model){
    PlayerBullet *bullets = model->playerBullets;
    PlayerShip *player = model->ship;
    int shoot = 0;
    int i = 0;
    int start = 0;                      /*to prevent the player bullet array from being traversed twice, we will tell it where to start off/continue from */
    while (i < NUM_PLAYER && model->ship[i].position.x != 0){
        player[i].prev_x = player[i].position.x;
        player[i].prev_y = player[i].position.y;
        move_player(&(model->ship[i]));
        start = process_player_bullet(&player[i],bullets,start);
        process_player_collisions(player,model->bullets);
        process_player_death(player);
        i++;
        }
    }


int process_player_bullet(PlayerShip *player, PlayerBullet *bullets, int start){
    int shoot = 0;
    int i = start;
    int end;
    if(player->fire_wep == 1)
        shoot = 1;
    while(i < NUM_BULLET && !end){
        if(bullets[i].position.y < -15 || bullets[i].collision == 1)
            despawn_player_bullet(&bullets[i]);
        if( shoot && bullets[i].position.x < 2 ) {
            if(bullets[i].position.x == 0)
                end = 1;
            bullets[i].position.y = player->position.y - 16;
            bullets[i].position.x = player->position.x;   /*find a bullet in the array not being used*/
            shoot = 0;                                       /*position 0 means no bullet at this point, or past that point has been used*/
            start = i;                                       /*1 means a bullet has since been despawned and can be used again*/         
            bullets[i].prev_x = bullets[i].position.x;
            bullets[i].prev_y = bullets[i].position.y;          /*record the snapshot*/   
        }                                                 
        else {
            if(bullets[i].position.x == 0)  
                end = 1;
            else if (!start && bullets[i].position.x != 1){
                bullets[i].prev_x = bullets[i].position.x;
                bullets[i].prev_y = bullets[i].position.y;          /*record the snapshot*/ 
                move_player_bullet(&bullets[i]);
            }
        }
        i++;
    }
    return start;
}
void process_player_collisions(PlayerShip *player, Bullet *bullets){
    int i = 0;
     while(i < NUM_BULLET && bullets[i].position.x != 0){
            if (check_collision(&(player->position), SHIP_WIDTH, SHIP_HEIGHT,&(bullets[i].position),BULLET_WIDTH,BULLET_HEIGHT)){
                bullets[i].position.x = 1;            /*reset the bullet to resting state, however now using x = 1*/
                bullets[i].position.y = 0;            /*as a value indicating previously used bullet*/
                player->hor_dir = 0;
                player->ver_dir = 0;
                player->collision = 1;                  /*mark ship for death*/
                player->fire_wep = 0;                   /*ensure ship wont fire in explosion process*/
            
            }
            i++;

    }
}

void process_player_death(PlayerShip *player){
    if (player->collision == 1 && player->death_time < 10)
        player->death_time++;
    else 
        respawn_player(player);

}

void process_enemy(Model *model){
    Bullet *bullets = model->bullets;
    Enemy *enemies = model->enemies;
    int start = 0;
    int i = 0;
    while(i < NUM_ENEMY && enemies->position.x != 0){
        if (enemies[i].position.x != 1){
            if(enemies[i].collision != 1){
                enemies[i].prev_x = enemies[i].position.x;
                enemies[i].prev_y = enemies[i].position.y;
            }
            move_enemy(&enemies[i]); 
            if (enemies[i].type == 1)
                start = process_helicopter_bullet(&enemies[i],bullets,start);
            else
                start = process_jet_bullet(&enemies[i],bullets,start);
            process_enemy_death(&enemies[i]);
            process_enemy_collisions(&enemies[i],model->playerBullets);

        }
        i++;
    }
}

int process_helicopter_bullet(Enemy *enemy, Bullet *bullets, int start){
    int i = start;
    int offset,end,shots,shoot = 0;
    if(enemy->cooldown == 0){
        shoot = 1;
        enemy->cooldown = 210;
    }
    while(i < NUM_BULLET && !end){
        if( shoot && bullets[i].position.x < 2 ) {
            if(bullets[i].position.x == 0 && shots == 3){
                end = 1;
                shoot = 0;
            }
            bullets[i].position.y = enemy->position.y - 16;
            bullets[i].position.x = enemy->position.x + offset;     
            if (offset == 0)
                bullets[i].hor_dir = LEFT;
            else if(offset == 32)
                bullets[i].hor_dir = RIGHT;
            offset += 16;                                           /*find a bullet in the array not being used*/                                          
            start = i;                                              /*position 0 means no bullet at this point, or past that point has been used*/
        }                                                            /*1 means a bullet has since been despawned and can be used again*/                                                            
        else {
            if(bullets[i].position.x == 0)  
                end = 1;
            else if (!start)
                move_enem_bullet(&bullets[i]);
        }
        i++;
    }
    return start;
}

int process_jet_bullet(Enemy *enemy, Bullet *bullets, int start){
     int i = start;
    int end,shots,shoot = 0;
    if(enemy->cooldown == 0){
        shoot = 1;
        enemy->cooldown = 210;
    }
    while(i < NUM_BULLET && !end){
        if( shoot && bullets[i].position.x < 2 ) {
            if(bullets[i].position.x == 0){
                end = 1;
            bullets[i].position.y = enemy->position.y - 16;
            bullets[i].position.x = enemy->position.x ;
            shoot = 0;     
            
                                                                   /*find a bullet in the array not being used*/                                          
            start = i;                                              /*position 0 means no bullet at this point, or past that point has been used*/
        }                                                            /*1 means a bullet has since been despawned and can be used again*/                                                            
        else {
            if(bullets[i].position.x == 0)  
                end = 1;
            else if (!start)
                move_enem_bullet(&bullets[i]);
        }
        i++;
    }
    return start;
}
}

void process_enemy_collisions(Enemy *enemy,PlayerBullet *bullets){
     int i = 0;
     while(i < NUM_BULLET && bullets[i].position.x != 0){
            if (check_collision(&(enemy->position), SHIP_WIDTH, SHIP_HEIGHT,&(bullets[i].position),BULLET_WIDTH,BULLET_HEIGHT)){
                bullets[i].collision = 1;
                enemy->hor_dir = 0;
                enemy->ver_dir = 0;
                enemy->collision = 1;                  /*mark ship for death*/
                enemy->fire_wep = 210;                   /*ensure ship wont fire in explosion process*/
                play_explosion();
            }
            i++;

    }
}

void process_enemy_death(Enemy * enemy){
    if (enemy->collision == 1 && enemy->death_time < 10){
            enemy->death_time++;      /*enemy will explode on screen for 10 clock cycles*/
    }
    else if (enemy->death_time == 10){
        despawn_enemy(enemy);
    }                                          /*if 10 clock cycles have occured, despawn the enemy*/        
}


PlayerShip * get_ship(Model *model){
    return (model->ship);
}
PlayerBullet * get_Pbullets(Model *model){
    return (model->playerBullets);
}