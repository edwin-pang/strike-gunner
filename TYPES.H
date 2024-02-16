#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 640

#define PLAYER_ONE 0
#define PLAYER_TWO 1

#define STOP 0
#define RIGHT 1
#define LEFT 2
#define UP 1
#define DOWN 2

#define QUIT 1

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef enum {
    RIGHT_KEY,
    LEFT_KEY,
    UP_KEY,
    DOWN_KEY
} keys;

#endif
