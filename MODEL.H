#ifndef MODEL_H
#define MODEL_H
#include "types.h"
#include "EFFECTS.H"
#include "PSG.H"

/*note to later change some of our spec properties to characters as 
i dont think we need the space ints take up for some of them*/

#define LEFT_BOUND_PLAYER   100
#define RIGHT_BOUND_PLAYER  540 
#define LEFT_BOUND_ENEMY_MOVEMENT    0
#define RIGHT_BOUND_ENEMY_MOVEMENT   640
#define SHIP_WIDTH 32
#define SHIP_HEIGHT 32
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 8
#define PLAYER_BULLET_WIDTH 32
#define PLAYER_BULLET_HEIGHT 16
#define POWER_UP_WIDTH 16
#define POWER_UP_HEIGHT 16
#define NUM_ENEMY 20
#define NUM_BULLET 50
#define NUM_PLAYER 1 /*for now*/
#define RIGHT 1
#define LEFT -1
#define UP 1
#define DOWN -1
#define STOP 0


typedef struct {
    int x, y;               /* This is a generic struct that contains x and y coordinates */
} Position;

typedef struct 
{
Position position;          /*horizontal and vertical postion of the player's ship*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
char hor_dir,ver_dir;       /*direction of movement, 1 for up or right, 2 for down or left*/
int prev_x,prev_y;          /*previous coords of Playership, this is a held snapshot*/
UINT8 wep_upgrade;          /*represents the current damage level of the main cannon*/
UINT8 fire_wep;             /*boolean flag for whether the main cannon is firing. 1 for fire, 0 for not*/
UINT8 fire_spec;            /*boolean flag for whether the special weapon is firing. 1 for fire, 0 for not*/
UINT8 lives;                /*amount of lives the player currently has*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 player shot, 2 obtained power-up*/
UINT8 death_time;           /*a value used to determine how long until player should respawn*/
} PlayerShip;


typedef struct 
{
Position position;          /*horizontal and vertical postion of the helicopter*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
char hor_dir,ver_dir;       /*direction of movement, 1 for up or right, 2 for down or left*/
int prev_x,prev_y;         /*previous coords of enemy, this is a held snapshot*/
UINT8 fire_wep;             /*boolean flag for whether the helicopter will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown;            /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
UINT8 cur_weapon;           /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
UINT16 value;               /*amount of points to be added to score upon elimination*/
UINT8 death_time;           /*a value used to determine how long until helicopter should despawn*/
UINT8 type;                 /*type of enemy. 1 for helicopter, 2 for jet*/
} Enemy;


typedef struct 
{
Position position;          /*horizontal and vertical postion of the score*/
UINT16 x_len; 
UINT16 y_len;               /*dimensions of score size*/    
UINT16 total;               /*the total score accumulated*/
} Score;

typedef struct 
{
Position position;          /*horizontal and vertical postion of the life counter*/
UINT16 x_len; 
UINT16 y_len;               /*dimensions of life counter size*/    
UINT16 health_bar;          /*current life count*/
} LifeCounter;

typedef struct 
{
Position position;          /*horizontal and vertical postion of the bullet*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
char hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
int prev_x,prev_y;          /*previous coords of bullet, this is a held snapshot*/
UINT8 damage;               /*amount of damage the bullet will do*/
UINT8 num;                  /*position in array*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 bullet to be destroyed*/
} Bullet;

typedef struct {
Position position;          /*horizontal and vertical postion of the bullet*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
char hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
int prev_x,prev_y;          /*previous coords of playerbullet, this is a held snapshot*/
UINT8 damage;               /*amount of damage the bullet will do*/
UINT8 num;                  /*position in array*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 player bullet to be destroyed*/
} PlayerBullet;

typedef struct 
{
Position position;          /*horizontal and vertical postion of the missile*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
char hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;               /*amount of damage the missile will do*/
UINT8 home_cd;              /*amount of time until missile will attempt to turn to player next clock cycle. player missiles wont home*/
UINT8 friendly;             /*boolean flag to determine whether missile is from a player (1) or not (0). players cant hurt players */
} Missile;

typedef struct
{
Position position;          /*horizontal and vertical postion of the powerup*/ 
UINT8 collision;            /*determines if player has collided with powerup. 0 for no, 1 for yes*/             
} PowerUp;

typedef struct{
PlayerShip ship[2];
Bullet bullets[50];
PlayerBullet playerBullets[50];
Missile missiles[25];
Enemy enemies[20];
Score score;
LifeCounter lives;
PowerUp powerup;
UINT8 quit_game;
UINT8 game_over;
UINT16 shot_time;
} Model;

/*
=====================================================================================================================
purpose:     will initialize a player ship with all of the necessary properties for the specified player.
input:       model  - pointer to the model struct where the player ship data will be initialized.
             player - integer representing the player index for what ship is being intialized.
output:      an initialized player ship in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_playership(Model *model, int player);

/*
=====================================================================================================================
purpose:     obtaining new player ship position according to its horizontal and vertical direction.
input:       player - pointer to the player ship struct that represents the ship to be moved.
output:      new player ship position (x and y values) that is based on the direction to be moved to.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_player (PlayerShip *player);

/*
=====================================================================================================================
purpose:     moving player ship position based on the specified horizontal and vertical direction within bounds.
input:       position   - pointer to the position struct representing current position of the ship.
             hor_dir    - unsigned 8-bit int representing horizontal direction of movement (1 for right, 2 for left).
             ver_dir    - unsigned 8-bit int representing vertical direction of movement (1 for up, 2 for down).
             speed      - the size of displacement per of the clock
             left_bound - unsigned 16-bit int representing the left boundary within which the ship can move.
             right_bound- unsigned 16-bit int representing the right boundary within which the ship can move.
output:      updated x or y coordinates of the player ship that is based on the direction to be moved to.
assumptions: N/A
limitations: movement is constrained within the specified boundaries.
             horizontal and vertical movements are independent and can occur within the same clock cycle.
bugs:        N/A
=====================================================================================================================
*/
void move_ship_pos(Position *position, char hor_dir, char ver_dir, UINT8 speed, UINT16 left_bound, UINT16 right_bound);

/*
=====================================================================================================================
purpose:     handling player shooting by initializing a player bullet's position if the player is ready to fire.
input:       player     - pointer to the position struct representing the player that is shooting.
             bullets    - pointer to the bullets array containing the player bullets.
output:      updated y coordinates of the player ship bullet that is being shot.
assumptions: player cannot fire all bullets in array at once during a given time, therefore bullets are "infinite".
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
/*int player_shoot (PlayerShip *player, PlayerBullet *bullets);*/

/*
=====================================================================================================================
purpose:     will initialize all helicopters in array with all of the necessary properties.
input:       model  - pointer to the model struct where the helicopter data will be initialized for each helicopter.
output:      an initialized array of helicopters in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
/*void init_helicopter(Model *model);*/

/*
=====================================================================================================================
purpose:     obtaining new helicopter position according to its horizontal and vertical direction.
input:       helicopter - pointer to the helicopter struct that represents the position to be moved.
output:      new helicopter position (x and y values) that is based on the direction to be moved to.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_enemy(Enemy *enemy);

/*
=====================================================================================================================
purpose:     moving enemy position based on the specified horizontal and vertical direction within bounds.
input:       position   - pointer to the position struct representing current position of the helicopter.
             hor_dir    - unsigned 8-bit int representing horizontal direction of movement (1 for right, 2 for left).
             ver_dir    - unsigned 8-bit int representing vertical direction of movement (1 for up, 2 for down).
             left_bound - unsigned 16-bit int representing the left boundary within which the helicopter can move.
             right_bound- unsigned 16-bit int representing the right boundary within which the helicopter can move.
output:      updated x or y coordinates of the helicopter that is based on the direction to be moved to.
assumptions: N/A
limitations: movement is constrained within the specified boundaries.
             horizontal and vertical movements are independent and can occur within the same clock cycle.
bugs:        N/A
=====================================================================================================================
*/
void move_heli_pos(Position *position, UINT8 hor_dir, UINT8 ver_dir, UINT16 left_bound, UINT16 right_bound);

/*
=====================================================================================================================
purpose:     will initialize all jets in array with all of the necessary properties.
input:       model  - pointer to the model struct where the jet data will be initialized for each jet.
output:      an initialized array of jets in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
/*void init_jet(Model *model);*/

/*
=====================================================================================================================
purpose:     obtaining new jet position according to its horizontal and vertical direction.
input:       jet - pointer to the jet struct that represents the position to be moved.
output:      new jet position (x and y values) that is based on the direction to be moved to.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
/*void move_jet(Jet *jet);*/

/*
=====================================================================================================================
purpose:     moving jet position based on the specified horizontal and vertical direction within bounds.
input:       position   - pointer to the position struct representing current position of the jet.
             hor_dir    - unsigned 8-bit int representing horizontal direction of movement (1 for right, 2 for left).
             ver_dir    - unsigned 8-bit int representing vertical direction of movement (1 for up, 2 for down).
             left_bound - unsigned 16-bit int representing the left boundary within which the jet can move.
             right_bound- unsigned 16-bit int representing the right boundary within which the jet can move.
output:      updated x or y coordinates of the jet that is based on the direction to be moved to.
assumptions: N/A
limitations: movement is constrained within the specified boundaries.
             horizontal and vertical movements are independent and can occur within the same clock cycle.
bugs:        N/A
=====================================================================================================================
*/
void move_jet_pos(Position *position, UINT8 hor_dir, UINT8 ver_dir, UINT16 left_bound, UINT16 right_bound);

/*
=====================================================================================================================
purpose:     will initialize scoreboard with all of the necessary properties.
input:       model  - pointer to the model struct where the scoreboard data will be initialized.
output:      an initialized scoreboard in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_score(Model *model);

/*
=====================================================================================================================
purpose:     update the total score in the model based on the current number of points the player collects.
input:       model  - pointer to the model struct containing the health bar and player ship data.
             value  - value to be added to the total in the score property.
output:      updates the total score value based on the how many points player is able to get.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void update_score(Model *model, int value);

/*
=====================================================================================================================
purpose:     will initialize a life counter with all of the necessary properties for the specified player.
input:       model  - pointer to the model struct where the life counter data will be initialized.
output:      an initialized life counter in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_life_counter(Model *model);

/*
=====================================================================================================================
purpose:     update the health bar in the model based on the current number of lives of the player ship.
input:       model  - pointer to the model struct containing the health bar and player ship data.
output:      updates the health bar value based on the whether the player ship lives are changed.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void update_lives(Model *model);

/*
=====================================================================================================================
purpose:     will initialize all enemy bullets with all of the necessary properties.
input:       model  - pointer to the model struct where the enemy bullets data will be initialized.
output:      an initialized array of enemy bullets in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_enem_bullets(Model *model);

/*
=====================================================================================================================
purpose:     move an enemy bullet vertically based on its speed
input:       bullet - pointer to the bullet struct representing the enemy bullet to be moved.
output:      updated y coordinate of the enemy bullet that is based on its speed.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_enem_bullet(Bullet *bullet);

/*
=====================================================================================================================
purpose:     will initialize all player bullets with all of the necessary properties.
input:       model  - pointer to the model struct where the player bullets data will be initialized.
output:      an initialized array of player bullets in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_player_bullets(Model *model);

/*
=====================================================================================================================
purpose:     move a player bullet vertically based on its speed
input:       playerBullet - pointer to the player bullet struct representing the enemy bullet to be moved.
output:      updated y coordinate of the player bullet that is based on its speed.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_player_bullet(PlayerBullet *playerBullet);

/*
=====================================================================================================================
purpose:     will initialize all missiles with all of the necessary properties.
input:       model  - pointer to the model struct where the missile data will be initialized.
output:      an initialized player ship in the model.
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_missile(Model *model);
void move_player_missile(Missile *missile);

/*
=====================================================================================================================
purpose:     check for collision between two objects based on their positions and dimensions.
input:       pos1  - pointer to the position struct representing the position of the first object.
             width1- unsigned 8-bit int representing the width of the first object.
             height1-unsigned 8-bit int representing the height of the first object.
             pos2  - pointer to the position struct representing the position of the second object.
             width2- unsigned 8-bit int representing the width of the second object.
             height2-unsigned 8-bit int representing the height of the second object.
output:      returns 1 if there is a collision detected, 0 otherwise.
assumptions: width and height parameters represent the dimensions of the correct object.
             objects are rectangular in shape.
limitations: collision detection is based on a simple bounding box collision method.
             positions and dimensions of both objects must be correct.
bugs:        N/A
=====================================================================================================================
*/
int check_collision(Position *pos1, UINT8 width1, UINT8 height1, Position *pos2, UINT8 width2, UINT8 height2);
/*
=====================================================================================================================
purpose:  make the the given helicopter fire its weapon, and reset its cooldown

input:      helicopter  -   pointer to a helicopter inside the helicopter array
            bullets     -   pointer to the array containing the enemy bullets

output:     bullets     -   bullets will be added to the playable area beneath the helicopter   

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)

limitations: bullets will not be fired if there is no room in the array for more
bugs:        N/A
=====================================================================================================================
*/
void enemy_shoot(Enemy *enemy, Bullet *bullets);
/*
=====================================================================================================================
purpose:    remove player bullet from screen and reserve in array for future usage

input:      bullet  -   pointer to a bullet in the array that needs to be despawned
            bullets -   the pointer to the array of player bullets

output:     bullets -   the specific bullet in the array will now be set to x = 1 and y = 0

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void despawn_player_bullet(PlayerBullet *bullet);
/*
=====================================================================================================================
purpose:     remove enemy bullet from screen and reserve in array for future usage

input:       bullet  -   pointer to a bullet in the array that needs to be despawned
             bullets -   the pointer to the array of enemy bullets

output:      bullets -   the specific bullet in the array will now be set to x = 1 and y = 0

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void despawn_enem_bullet(Bullet *bullet);
/*
=====================================================================================================================
purpose:     remove helicopter from screen and reserve in array for future usage

input:       helicopter  -   pointer to a helicopter in the array that needs to be despawned
             helicopters -   the pointer to the array of helicopters

output:      helicopters -   the specific helicopter in the array will now be set to x = 1 and y = 0,
                             and have its other properties returned to default
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void despawn_enemy(Enemy *enemy);
/*
=====================================================================================================================
purpose:      remove jet from screen and reserve in array for future usage

input:       jet  -   pointer to a jet in the array that needs to be despawned
             jets -   the pointer to the array of jets

output:     jets  -   the specific jet in the array will now be set to x = 1 and y = 0,
                      and have its other properties returned to default

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
/*void despawn_jet(Jet *jet, Jet *jets);*/
/*
=====================================================================================================================
purpose:     initialize all components of the games model needed to start the game

input:       model       -   the pointer to the model of the game which houses all information  

output:      model       -  all components of the model will be changed to their default state 

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
             it is also assumed this will only ever be called at the games start
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void init_model(Model *model);
/*
=====================================================================================================================
purpose:  if the player still has lives, respawn the player upon death

input:      player  -   pointer to a player ship object

output:     player  -   will have the following properties changed: x = 288, y = 368, lives = lives - 1
                        wep_upgrade = 10, fire_wep = 0, collision = 0, death_time = 0
assumptions: this function on its own will not alter the game's state upon the player reaching 0 lives,
             the game will need to check for this on its own
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void respawn_player(PlayerShip *player);
void process_player(Model *model);
int process_player_bullet(PlayerShip *player, PlayerBullet *bullets, int start);
void process_player_collisions(PlayerShip *player, Bullet *bullets);
void process_player_death(PlayerShip *player);
void process_enemy(Model *model);
int process_helicopter_bullet(Enemy *enemy, Bullet *Bullets, int start);
int process_jet_bullet(Enemy *enemy, Bullet *bullets, int start);
void process_enemy_collisions(Enemy *enemy,PlayerBullet *bullets);
void process_enemy_death(Enemy * enemy);
Score get_score(Model *model);
LifeCounter get_life(Model *model);
PlayerShip * get_ship(Model *model);
PlayerBullet * get_Pbullets(Model *model);
#endif