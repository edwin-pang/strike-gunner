/*note to later change some of our spec properties to characters as i dont think we need the space ints take up for some of them*/

/*By the way C doesn't actaully have booleans, so we need to use something else instead*/

typedef struct 
{
UINT16 x,y;               /*horizontal and vertical postion of the player's ship*/              
const UINT8 speed = 1;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 wep_upgrade = 1;    /*represents the current damage level of the main cannon*/
UINT8 fire_wep = 0;       /*boolean flag for whether the main cannon is firing. 1 for fire, 0 for not*/
UINT8 fire_spec;          /*boolean flag for whether the special weapon is firing. 1 for fire, 0 for not*/
UINT8 health = 3;         /*amount of lives the player currently has*/
UINT* collision = 0;      /*a value used to determine the type of collsion, 0 none, 1 player shot, 2 obtained power-up*/

} PlayerShip;


typedef struct 
{
UINT16 x,y;                 /*horizontal and vertical postion of the helicopter*/              
const UINT8 speed = 1;      /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 fire_wep = 0;         /*boolean flag for whether the helicopter will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown = 210       /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
const UINT8 cur_weapon = 1; /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision = 0;        /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
const UINT16 score = 100;   /*amount of points to be added to score upon elimination*/

} Helicopter;

typedef struct 
{ 
UINT16 x,y;                 /*horizontal and vertical postion of the jet*/              
UINT8 speed;                /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;      /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 fire_wep = 0;         /*boolean flag for whether the jet will fire next clock cycle. 1 for fire, 0 for not. After firing reset to 0*/
UINT16 cooldown = 210       /*amount of time until the fire_wep flag is set, this will then reset to 210 (3 seconds) */
const UINT8 cur_weapon = 2; /*value specifies weapon held. 1 for bullet, 2 for missile*/
UINT8 collision = 0;        /*a value used to determine the type of collsion, 0 none, 1 helicopter to be destroyed*/
const UINT16 score = 150;   /*amount of points to be added to score upon elimination*/

} Jet;

typedef struct 
{
UINT16 x,y;               /*horizontal and vertical postion of the score*/
const UINT16 x_len = 32; 
const UINT16 y_len = 32;  /*dimensions of score size*/    
UINT16 value = 0;         /*the total score accumulated*/

} Score;

typedef struct 
{
UINT16 x,y;               /*horizontal and vertical postion of the life counter*/
const UINT16 x_len = 32; 
const UINT16 y_len = 32;  /*dimensions of life counter size*/    
UINT16 health_bar = 3;    /*current life count*/

} lifeCounter;

typedef struct 
{
UINT16 x,y;               /*horizontal and vertical postion of the bullet*/              
const UINT8 speed = 1;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;             /*amount of damage the bullet will do*/
UINT8 friendly;           /*boolean flag to determine whether bullet is from a player (1) or not (0). players cant hurt players */

} Bullet;

typedef struct 
{
UINT16 x,y;               /*horizontal and vertical postion of the missile*/              
const UINT8 speed = 1;    /*rate of displacement for movement in any direction (pixels per clock cycle)*/
UINT8 hor_dir,ver_dir;    /*direction of movement, 1 for up or right, 2 for down or left*/
UINT8 damage;             /*amount of damage the missile will do*/
UINT8 home_cd;            /*amount of time until missile will attempt to turn to player next clock cycle. player missiles wont home*/
UINT8 friendly;           /*boolean flag to determine whether missile is from a player (1) or not (0). players cant hurt players */

} Missile;

typedef struct
{
UINT16 x,y;               /*horizontal and vertical postion of the powerup*/ 
UINT8 collision;          /*determines if player has collided with powerup. 0 for no, 1 for yes*/             

} PowerUp;