#ifndef RENDERER_H
#define RENDERER_H
#define LEFT_BOUND_ENEMY_RENDER 
#define RIGHT_BOUND_ENEMY_RENDER
#include "TYPES.H"
#include "RASTER.H"
#include "MODEL.H"
#include "font.h"
/*
=====================================================================================================================
purpose:     render the left panel on the screen where information of player 1 will be held

input:       base           -   memory location of (0,0) in the frame buffer

output:      frame buffer   -   frame buffer will be altered to render this left panel

assumptions: assumes that no entity will utilize this area in gameplay 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void render_panel_left(UINT32 *base);
/*
=====================================================================================================================
purpose:     render the right panel on the screen where information of player 2 will be held

input:       base           -   memory location of (0,0) in the frame buffer

output:      frame buffer   -   frame buffer will be altered to render this right panel

assumptions: assumes that no entity will utilize this area in gameplay 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void render_panel_right(UINT32 *base);
/*
=====================================================================================================================
purpose:    render all of the 32 length bitmaps onto the screen, if they are in the playable area

input:      model          -   the pointer to the games model which possesses all game information
            base           -   memory location of (0,0) in the frame buffer

output:     frame buffer   -   frame buffer will be altered to render all present 32 bitmaps

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void render_all_32(Model *model, UINT32 *base);
/*
=====================================================================================================================
purpose:    render all of the 8 length bitmaps onto the screen, if they are in the playable area

input:      model          -   the pointer to the games model which possesses all game information
            base           -   memory location of (0,0) in the frame buffer

output:     frame buffer   -   frame buffer will be altered to render all present 8 bitmaps

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void render_all_8(Model *model, UINT8 *base);
/*
=====================================================================================================================
purpose:    render all of the 16 length bitmaps onto the screen, if they are in the playable area

input:      model          -   the pointer to the games model which possesses all game information
            base           -   memory location of (0,0) in the frame buffer

output:     frame buffer   -   frame buffer will be altered to render all present 16 bitmaps
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void render_all_16(Model *model, UINT16 *base);
/*
=====================================================================================================================
purpose:    render every single object that is in the playing field, as well as everything
            inside the left and right panels

input:      model          -   the pointer to the games model which possesses all game information

output:     frame buffer   -   frame buffer will be altered to render everything

assumptions: It isn't technically neccessary, but heavily assumed that parts of the screen that "move"
             are cleared before rendering again, otherwise the screen will not look very cohesive 
limitations: Will not render objects that land outside the playable area (objects not meant to be there)
bugs:        N/A
=====================================================================================================================
*/
void render(Model *model, UINT8 *base);
/*
=====================================================================================================================
purpose:    render the current in game score into the left panel     

input:      model          -   the pointer to the games model which possesses all game information
            base           -   memory location of (0,0) in the frame buffer

output:     frame buffer   -   frame buffer will be altered to render the score
assumptions: it is assumed that the score does not exceed the 16-bit max number, as there should not be
             enough enemies in game to even permit this scenario
limitations: this will print 5 digits no matter what, if a number is less than 5 digits in length,
             it will be led with leading zeros
bugs:        N/A
=====================================================================================================================
*/
void render_score(Model *model, UINT8 *base);
/*
=====================================================================================================================
purpose:     

input:      
output:     
assumptions: 
limitations: 
bugs:        
=====================================================================================================================
*/
void render_clear();
void render_enemies(Model *model, UINT32 *base);
void render_moveables(Model *model, char *base);
void clear_32(UINT16 height, UINT16 x, UINT16 y, UINT8 hor_dir, UINT8 Ver_dir);
void clear_8(Model *model, UINT8 *base);
void clear_16(Model *model, UINT16 *base);
void clear_moveables(Model *model);
void clear_score(Model *model);

void clear_lives(Model *model);
void check_snapshot(UINT8 *base);
void snap_player(UINT8 *base);
void snap_enemy(UINT8 *base);
 void snap_enemy_bullet(UINT8 *base);
#endif