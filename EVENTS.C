#include "EVENTS.H"
#include "MODEL.H"


void move_up_request(PlayerShip *player) {
    player->ver_dir = UP;                    /*will change the player's vertical direction to 1 for up*/
}

void move_up_cancel(PlayerShip *player) {
    player->ver_dir = STOP;                    /*will change the player's vertical direction to 0 for nothing*/
}
void move_down_request(PlayerShip *player) {
    player->ver_dir = DOWN;                    /*will change the player's vertical direction to 2 for down*/
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
    player->hor_dir = LEFT;                    /*will change the player's horizontal direction to 2 for left*/
}

void move_left_cancel(PlayerShip *player) {
    player->hor_dir = STOP;                    /*will change the player's horizontal direction to 0 for nothing*/
}


void fire_main_request(PlayerShip *player) {
    player->fire_wep = TRUE;                   /*will change the player's main weapon flag to 1 for true*/
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

void move_all(Model *model){
    move_ships(model->ship,model->helicopters,model->jets);
    move_bullets(model->playerBullets,model->bullets);
}

void move_ships(PlayerShip *players, Helicopter *helicopters, Jet *jets){
int i = 0;
move_player(players);
if ((players + 1)->position.x != 0) {
    move_player(players + 1);
}
while (i < 20 && helicopters[i].position.x != 0){
    move_heli(helicopters + i);
    i++;
}
i = 0;
while (i < 20 && jets[i].position.x != 0){
    move_jet(jets + i);
    i++;
}
}

void move_bullets(PlayerBullet *player_bullets, Bullet *bullets){
    int i = 0;
    while (i < 50 && player_bullets[i].position.x != 0){
    move_player_bullet(player_bullets + i);
    i++;
}
i = 0;
    while (i < 50 && bullets[i].position.x != 0){
    move_enem_bullet(bullets + i);
    i++;
}
}

void players_shoot(PlayerShip *players, PlayerBullet *bullets){
    player_shoot(players, bullets);
    if ((players + 1)->position.x != 0){
    player_shoot(players + 1, bullets);
    }
}
void helicopters_shoot(Helicopter *helicopters, Bullet *bullets){
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
            if (check_collision(&(helicopters[j].position), SHIP_WIDTH, SHIP_HEIGHT,&(bullets[i].position), PLAYER_BULLET_WIDTH,PLAYER_BULLET_HEIGHT)){
                
            }
        }
    }
}