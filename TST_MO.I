# 1 "tst_mo.c" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/osbind.h" 2
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 1 "tst_mo.c" 2
# 1 "./model.h" 1
# 1 "./TYPES.H" 1



typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 6 "./model.h" 2
# 12 "./model.h"
typedef struct {
    int x, y;
} Position;

typedef struct
{
Position position;
const UINT8 speed = 1;
UINT8 hor_dir,ver_dir;
UINT8 wep_upgrade = 1;
UINT8 fire_wep = 0;
UINT8 fire_spec;
UINT8 health = 3;
UINT* collision = 0;

} PlayerShip;


typedef struct
{
Position position;
const UINT8 speed = 1;
UINT8 hor_dir,ver_dir;
UINT8 fire_wep = 0;
UINT16 cooldown = 210
const UINT8 cur_weapon = 1;
UINT8 collision = 0;
const UINT16 score = 100;

} Helicopter;

typedef struct
{
Position position;
UINT8 speed;
UINT8 hor_dir,ver_dir;
UINT8 fire_wep = 0;
UINT16 cooldown = 210
const UINT8 cur_weapon = 2;
UINT8 collision = 0;
const UINT16 score = 150;

} Jet;

typedef struct
{
Position position;
const UINT16 x_len = 32;
const UINT16 y_len = 32;
UINT16 value = 0;

} Score;

typedef struct
{
Position position;
const UINT16 x_len = 32;
const UINT16 y_len = 32;
UINT16 health_bar = 3;

} LifeCounter;

typedef struct
{
Position position;
const UINT8 speed = 1;
UINT8 hor_dir,ver_dir;
UINT8 damage;
} Bullet;

typedef struct {
Position position;
const UINT8 speed = 1;
UINT8 hor_dir,ver_dir;
UINT8 damage;
} PlayerBullet;

typedef struct
{
Position position;
const UINT8 speed = 1;
UINT8 hor_dir,ver_dir;
UINT8 damage;
UINT8 home_cd;
UINT8 friendly;

} Missile;

typedef struct
{
Position position;
UINT8 collision;

} PowerUp;

typedef struct{
PlayerShip player;
Bullet bullets[50] = new array[50];
PlayerBullet PlayerBullets[50] = new array[50];
Missile missiles[25] = new array [25];
Helicopter helicopters[20] = new array[20];
Jet jets[20] = new array[20];
Score score;
LifeCounter lives;

} Model;

void move_player (PlayerShip player);
void player_shoot (PlayerShip player, Model model);
void move_bullet(Bullet *bullet);
int check_collision(Position *pos1, Position *pos2);
void update_score(Score *score, int value);
void move_heli_down(Helicopter *helicopter);
# 2 "tst_mo.c" 2
# 1 "./TYPES.H" 1
# 3 "tst_mo.c" 2


int main()
{
    PlayerShip player;
    Bullet bullet;

    player.position.x = 320;
    player.position.y = 200;

    bullet.position.x = 320;
    bullet.position.y = 300;

    printf(check_collision(*player.position, *bullet.position));

    bullet.position.x = 320;
    bullet.position.y = 230;

    printf(check_collision(*player.position, *bullet.position));
}
