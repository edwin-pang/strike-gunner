#include "EVENTS.H"
#include "MODEL.H"
#include "EFFECTS.H"
#include "PSG.H"
#include "STRIKE.H"
#include "TST_EV.H"
#include "INPUT.H"


void key_request(){
    UINT8 key = get_key();
    if(key == 'w'){
        model.ship->ver_dir = UP; 
    }
    else if(key == 's'){
        model.ship->ver_dir = DOWN; 
        }
    else if(key == 'a'){
        model.ship->hor_dir = LEFT;         
    }   
    else if(key == 'd'){
        model.ship->hor_dir = RIGHT; 
    }
    else if(key == 'x' && model.shot_time >= 35){
        model.ship->fire_wep = TRUE; 
        model.shot_time = 0;
        play_bullet();
    }
    else if (key == ESC_KEY){
        model.quit_game = TRUE;
    }
}
void sync_event_check(){
        process_player(&model);
        process_enemy(&model);
}
void move_up_request(PlayerShip *player) {
    model.ship->ver_dir = UP;                    /*will change the player's vertical direction to 1 for up*/
}

void move_up_cancel(PlayerShip *player) {
    player->ver_dir = STOP;                    /*will change the player's vertical direction to 0 for nothing*/
}
void move_down_request(PlayerShip *player) {
    player->ver_dir = DOWN;                    /*will change the player's vertical direction to -1 for down*/
}

void move_down_cancel(PlayerShip *player) {
    player->ver_dir = STOP;                    /*will change the player's vertical direction to 0 for nothing*/
}

void move_right_request(PlayerShip *player) {
    player->hor_dir = RIGHT;                   /*will change the player's horizontal direction to 1 for right*/
}

void move_right_cancel(PlayerShip *player) {
    player->hor_dir = STOP;                    /*will change the player's horizontal direction to 0 for nothing*/
}

void move_left_request(PlayerShip *player) {
    player->hor_dir = LEFT;                    /*will change the player's horizontal direction to -1 for left*/
}

void move_left_cancel(PlayerShip *player) {
    player->hor_dir = STOP;                    /*will change the player's horizontal direction to 0 for nothing*/
}


void fire_main_request(PlayerShip *player) {
    player->fire_wep = TRUE;                   /*will change the player's main weapon flag to 1 for true*/
    play_bullet();
}


void fire_main_cancel(PlayerShip *player) {
    player->fire_wep = FALSE;                  /*will change the player's main weapon flag to 0 for false*/
}

void fire_spec_request(PlayerShip *player){
    player->fire_spec = TRUE;                  /*will change the player's special fire flag to 1 for true*/
}

void fire_spec_cancel(PlayerShip *player){
    player->fire_spec = FALSE;                 /*will change the player's special fire flag to 0 for false*/
}

void quit_game(Model *model) {
    model->quit_game = QUIT;                   /*will change the model's quit game flag to 1 for true*/
}

/*void move_all(Model *model){
    move_ships(model->ship,model->helicopters,model->jets);
    move_bullets(model->playerBullets,model->bullets);
}

void move_ships(PlayerShip *players, Helicopter *helicopters, Jet *jets){
int i = 0;
move_player(players);
if (players[1].position.x != 0) {
    move_player(&players[1]);
}
while (i < 20 && helicopters[i].position.x != 0){
    move_heli(&helicopters[i]);
    i++;
}
i = 0;
while (i < 20 && jets[i].position.x != 0){
    move_jet(&jets[i]);
    i++;
}
}
*/
void move_bullets(PlayerBullet *player_bullets, Bullet *bullets){
    int i = 0;
    while (i < 50 && player_bullets[i].position.x != 0){
        if (player_bullets[i].position.y <= 1){
            despawn_player_bullet(&player_bullets[i]);
        }                           /*bullet off screen, remove it*/
        else{
            move_player_bullet(&(player_bullets[i]));
        }   
        i++;                        /*move bullet once by speed property*/
    }
    i = 0;
    while (i < 50 && bullets[i].position.x != 0){
         if (bullets[i].position.y >= 392){
            despawn_enem_bullet(&bullets[i]);
        } 
        else {
            move_enem_bullet(&bullets[i]);
            i++;
        }
    }
}
/*
void players_shoot(PlayerShip *players, PlayerBullet *bullets){
    player_shoot(players, bullets);
    if ((&players[1])->position.x != 0){
    player_shoot(&players[1], bullets);
    }
}
*/
/*void helicopters_shoot(Helicopter *helicopters, Bullet *bullets){
    int i = 0;
    while (i < 19 && helicopters[i].position.x != 0){
        if (helicopters[i].cooldown == 0){
            heli_shoot(helicopters,bullets);
        }
        else{
            helicopters[i].cooldown--;
        }
        i++;
    }
}

void shoot_bullets(Model *model){
    players_shoot(model->ship,model->playerBullets);        
    helicopters_shoot(model->helicopters,model->bullets);
}

void check_heliopter_hit(Helicopter *helicopters, PlayerBullet *bullets){
    int i = 0;
    int j = 0;
    while (i < NUM_ENEMY && helicopters[i].position.x != 0){
        while(j < NUM_BULLET && bullets[j].position.x != 0){
            if (check_collision(&(helicopters[i].position), SHIP_WIDTH, SHIP_HEIGHT,&(bullets[j].position), PLAYER_BULLET_WIDTH,PLAYER_BULLET_HEIGHT)){
                despawn_player_bullet(&(bullets[j]), bullets); 
                helicopters[i].collision = 1;                  
                helicopters[i].cooldown = 210;                 
            }
            j++;
        }
        i++;
    }
}
*/
/*void destroy_helicopters(Helicopter *helicopters){
    int i = 0;
    while (i < NUM_ENEMY && helicopters[i].position.x != 0){
        if (helicopters[i].collision == 1 && helicopters[i].death_time < 10){
            helicopters[i].death_time++;     
        }
        else if (helicopters[i].death_time == 10){
            despawn_helicopter(&helicopters[i],helicopters);
                                             
        }
        i++;
    }
}
void destroy_jets(Jet *jets){
    int i = 0;
    while (i < NUM_ENEMY && jets[i].position.x != 0){
        if (jets[i].collision == 1 && jets[i].death_time < 10){
            jets[i].death_time++;     
        }
        else if (jets[i].death_time == 10){
            despawn_jet(&jets[i],jets);
                                              
        }
        i++;
    }*/

void check_player_hit(PlayerShip *player, Bullet *bullets){
    int i = 0;
    int j = 0;
    while (i < NUM_PLAYER && player[i].position.x != 0){
        while(j < NUM_BULLET && bullets[j].position.x != 0){
            if (check_collision(&(player[i].position), SHIP_WIDTH, SHIP_HEIGHT,&(bullets[j].position),BULLET_WIDTH,BULLET_HEIGHT)){
                despawn_enem_bullet(&(bullets[j])); /*remove intercepting bullet*/
                player[i].hor_dir = 0;
                player[i].ver_dir = 0;
                player[i].collision = 1;                  /*mark ship for death*/
                player[i].fire_wep = 0;                   /*ensure ship wont fire in explosion process*/
            }
            j++;
        }
        i++;
}
}
/*void check_enemy_hit(Model *model){
check_heliopter_hit(model->helicopters,model->playerBullets);
}

void check_collisions(Model *model){
    check_enemy_hit(model);
    check_player_hit(model->ship,model->bullets);
}



void destroy_player(PlayerShip *player){
    int i = 0;
    while (i < NUM_PLAYER && player[i].position.x != 0){
        if (player[i].collision == 1 && player[i].death_time < 10){
            player[i].death_time++;
    }
    else if (player[i].death_time == 10){
        respawn_player(player);
    }
    i++;
    }
}

void destroy_all(Model *model){
    destroy_player(model->ship);
    destroy_helicopters(model->helicopters);
}
*/