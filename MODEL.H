typedef struct
{
    unsigned int x, y;
    int speed;
    int delta_x, delta_y;       /* this could change, just comparing with game stage 3 spec */
    int weapon_upgrade_val;
    bool fire_weapon;
    bool fire_special_weapon;
    int health_bar;
    int collision;

} PlayerShip;

typedef struct
{
    unsigned int x, y;
    const int speed;
    int delta_x, delta_y;
    bool fire_weapon;
    int attack_cooldown;
    int weapon_type;
    int collision;              /* what is the difference between int and bool for collision? */
    const int score_value;

} Helicopter;

typedef struct
{
    unsigned int x, y;
    const int speed;
    int delta_x, delta_y;
    bool fire_weapon;
    int attack_cooldown;
    int weapon_type;
    int collision;
    const int score_value;

} Jet;

typedef struct
{
    const unsigned int x, y;
    const unsigned int x_length, y_length;
    int value;

} Score;

typedef struct
{
    const unsigned int x, y;
    const unsigned int x_length, y_length;
    int value;

} LifeCounter;

typedef struct
{
    unsigned int x, y;
    const int speed;
    int delta_x, delta_y;
    int damage_amount;
    bool friendly;

} Bullet;

typedef struct 
{
    unsigned int x, y;
    const int speed;
    int delta_x, delta_y;
    int damage_amount;
    int cooldown;
    bool friendly;

} Missile;

typedef struct 
{
    unsigned int x, y;
    int collsion;

} PowerUp;


