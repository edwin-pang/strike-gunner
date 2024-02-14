#ifndef MODEL_H
#define MODEL_H
/*note to later change some of our spec properties to characters as i dont think we need the space ints take up for some of them*/

/*By the way C doesn't actaully have booleans, so we need to use something else instead*/

/*reminder to add function prototypes here later*/

#include "types.h"
#define LEFT_BOUND_PLAYER   50
#define RIGHT_BOUND_PLAYER  590 
#define LEFT_BOUND_ENEMY    0
#define RIGHT_BOUND_ENEMY   640
#define PLAYER_WIDTH 32


typedef struct {
    int x, y;             /* This is a generic struct that contains x and y coordinates */
} Position;               /* We can change int to something else if we don't need to alloc that much for position*/

typedef struct 
{
Position position;        /*horizontal and vertical postion of the player's ship*/              
const UINT8 speed;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 wep_upgrade;    /*represents the current damage level of the main cannon*/
UINT8 fire_wep;       /*boolean flag for whether the main cannon is firing. 1 for fire, 0 for not*/
UINT8 fire_spec;          /*boolean flag for whether the special weapon is firing. 1 for fire, 0 for not*/
UINT8 health;         /*amount of lives the player currently has*/
UINT8 collision;      /*a value used to determine the type of collsion, 0 none, 1 player shot, 2 obtained power-up*/

} PlayerShip;


typedef struct 
{
Position position;          /*horizontal and vertical postion of the helicopter*/              
const UINT8 speed;      /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 fire_wep;         /*boolean flag for whether the helicopter will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown;       /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
const UINT8 cur_weapon; /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision;        /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
const UINT16 score;   /*amount of points to be added to score upon elimination*/

} Helicopter;

typedef struct 
{ 
Position position;          /*horizontal and vertical postion of the jet*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 fire_wep;         /*boolean flag for whether the jet will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown;       /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
const UINT8 cur_weapon; /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision;        /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
const UINT16 score;   /*amount of points to be added to score upon elimination*/

} Jet;

typedef struct 
{
Position position;        /*horizontal and vertical postion of the score*/
const UINT16 x_len; 
const UINT16 y_len;  /*dimensions of score size*/    
UINT16 value;         /*the total score accumulated*/

} Score;

typedef struct 
{
Position position;        /*horizontal and vertical postion of the life counter*/
const UINT16 x_len; 
const UINT16 y_len;  /*dimensions of life counter size*/    
UINT16 health_bar;    /*current life count*/

} LifeCounter;

typedef struct 
{
Position position;        /*horizontal and vertical postion of the bullet*/              
const UINT8 speed;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;             /*amount of damage the bullet will do*/
} Bullet;

typedef struct {
Position position;        /*horizontal and vertical postion of the bullet*/              
const UINT8 speed;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;             /*amount of damage the bullet will do*/
} PlayerBullet;

typedef struct 
{
Position position;        /*horizontal and vertical postion of the missile*/              
const UINT8 speed;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;             /*amount of damage the missile will do*/
UINT8 home_cd;            /*amount of time until missile will attempt to turn to player next clock cycle. player missiles wont home*/
UINT8 friendly;           /*boolean flag to determine whether missile is from a player (1) or not (0). players cant hurt players */

} Missile;

typedef struct
{
Position position;               /*horizontal and vertical postion of the powerup*/ 
UINT8 collision;          /*determines if player has collided with powerup. 0 for no, 1 for yes*/             

} PowerUp;

typedef struct{
PlayerShip player;
Bullet bullets[50];
PlayerBullet PlayerBullets[50];
Missile missiles[25];
Helicopter helicopters[20];
Jet jets[20];
Score score;
LifeCounter lives;

} Model;

void move_player (PlayerShip *player);
void player_shoot (PlayerShip *player, Model *model);
void move_bullet(Bullet *bullet);
int check_collision(Position *pos1, Position *pos2);
void update_score(Score *score, int value);
void move_heli_down(Helicopter *helicopter);

#endif