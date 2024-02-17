#ifndef MODEL_H
#define MODEL_H
#include "types.h"

/*note to later change some of our spec properties to characters as 
i dont think we need the space ints take up for some of them*/

#define LEFT_BOUND_PLAYER   100
#define RIGHT_BOUND_PLAYER  540 
#define LEFT_BOUND_ENEMY    0
#define RIGHT_BOUND_ENEMY   640
#define SHIP_WIDTH 32
#define SHIP_HEIGHT 32
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 8
#define PLAYER_BULLET_WIDTH 32
#define PLAYER_BULLET_HEIGHT 16
#define POWER_UP_WIDTH 16
#define POWER_UP_HEIGHT 16
#define NUM_ENEMY 19
#define NUM_BULLET 49


typedef struct {
    int x, y;               /* This is a generic struct that contains x and y coordinates */
} Position;

typedef struct 
{
Position position;          /*horizontal and vertical postion of the player's ship*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 wep_upgrade;          /*represents the current damage level of the main cannon*/
UINT8 fire_wep;             /*boolean flag for whether the main cannon is firing. 1 for fire, 0 for not*/
UINT8 fire_spec;            /*boolean flag for whether the special weapon is firing. 1 for fire, 0 for not*/
UINT8 lives;                /*amount of lives the player currently has*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 player shot, 2 obtained power-up*/
} PlayerShip;


typedef struct 
{
Position position;          /*horizontal and vertical postion of the helicopter*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 fire_wep;             /*boolean flag for whether the helicopter will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown;            /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
UINT8 cur_weapon;           /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
UINT16 value;               /*amount of points to be added to score upon elimination*/
} Helicopter;

typedef struct 
{ 
Position position;          /*horizontal and vertical postion of the jet*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 fire_wep;             /*boolean flag for whether the jet will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown;            /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
UINT8 cur_weapon;           /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision;            /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
UINT16 value;               /*amount of points to be added to score upon elimination*/
} Jet;

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
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;               /*amount of damage the bullet will do*/
} Bullet;

typedef struct {
Position position;          /*horizontal and vertical postion of the bullet*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;               /*amount of damage the bullet will do*/
} PlayerBullet;

typedef struct 
{
Position position;          /*horizontal and vertical postion of the missile*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
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
Helicopter helicopters[20];
Jet jets[20];
Score score;
LifeCounter lives;
PowerUp powerup;
UINT8 quit_game;
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
             left_bound - unsigned 16-bit int representing the left boundary within which the ship can move.
             right_bound- unsigned 16-bit int representing the right boundary within which the ship can move.
output:      updated x or y coordinates of the player ship that is based on the direction to be moved to.
assumptions: N/A
limitations: movement is constrained within the specified boundaries.
             horizontal and vertical movements are independent and can occur within the same clock cycle.
bugs:        N/A
=====================================================================================================================
*/
void move_ship_pos(Position *position, UINT8 hor_dir, UINT8 ver_dir, UINT16 left_bound, UINT16 right_bound);

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
void player_shoot (PlayerShip *player, PlayerBullet *bullets);

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
void init_helicopter(Model *model);

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
void move_heli(Helicopter *helicopter);

/*
=====================================================================================================================
purpose:     moving helicopter position based on the specified horizontal and vertical direction within bounds.
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
void init_jet(Model *model);

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
void move_jet(Jet *jet);

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

void heli_shoot(Helicopter *helicopter, Bullet *bullets);


#endif