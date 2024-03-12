#ifndef EVENTS_H
#define EVENTS_H
#include "MODEL.H"
#include "TYPES.H"
#include "EFFECTS.H"
/*
=====================================================================================================================
purpose:    this is intended to be called when a player presses "up", changing vertical direction
            to up

input:       player     - the player ship that having it's vertical direction change

output:      ver_dir    - the ver_dir property of the player will be changed to 1       

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_up_request(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player releases "up", changing vertical direction
             back to nothing

input:       player     - the player ship that having it's vertical direction change

output:      ver_dir    - the ver_dir property of the player will be changed to 0 

assumptions: this function will be used asynchronously and only through keyboard releases
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_up_cancel(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player depresses "down", changing vertical direction
             to 2

input:       player     - the player ship that having it's vertical direction change

output:      ver_dir    - the ver_dir property of the player will be changed to 2

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_down_request(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player releases "down", changing vertical direction
             back to 0

input:       player     -  the player ship that having it's vertical direction change

output:      ver_dir    - the ver_dir property of the player will be changed to 0

assumptions: this function will be used asynchronously and only through keyboard releases
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_down_cancel(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player depresses "right", changing horizontal direction
             to 1

input:       player     - the player ship that having it's horizontal direction change

output:      hor_dir    - the hor_dir property of the player will be changed to 1

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_right_request(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player releases "right", changing horizontal direction
             back to 0

input:       player     - the player ship that having it's horizontal direction change

output:      hor_dir    - the hor_dir property of the player will be changed to 0

assumptions: this function will be used asynchronously and only through keyboard releases
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_right_cancel(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player releases "left", changing horizontal direction
             to 2

input:       player     - the player ship that having it's horizontal direction change

output:      hor_dir    - the hor_dir property of the player will be changed to 2

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_left_request(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player releases "left", changing horizontal direction
             back to 0

input:       player     - the player ship that having it's horizontal direction change

output:      hor_dir    - the hor_dir property of the player will be changed to 0

assumptions: this function will be used asynchronously and only through keyboard releases
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_left_cancel(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player depresses "x", changing the fire weapon  
             flag to 1 (true)

input:       player    - the player ship that having it's fire weapon flag change

output:      fire_wep  - the fire_wep flag property of the player is changed to 1

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void fire_main_request(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player releases "x", changing the fire weapon  
             flag back to 0 (false)

input:       player    - the player ship that having it's fire weapon flag change

output:      fire_wep  - the fire_wep flag property of the player is changed to 0

assumptions: this function will be used asynchronously and only through keyboard releases
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void fire_main_cancel(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player depresses "c", changing the special weapon  
             flag to 1 (true)

input:       player     - the player ship that having it's special weapon flag change

output:      fire_spec  - the spec_wep flag property of the player is changed to 1

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void fire_spec_request(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player depresses "c", changing the special weapon  
             flag back to 0 (false)

input:       player     - the player ship that having it's special weapon flag change

output:      fire_spec  - the spec_wep flag property of the player is changed to 0

assumptions: this function will be used asynchronously and only through keyboard releases

limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void fire_spec_cancel(PlayerShip *player);
/*
=====================================================================================================================
purpose:     this is intended to be called when a player depresses "esc", changing the  game quit  
             flag back to 1 (true)

input:       model  -   the model that having it's quit flag change

output:      quit   -  the  quit flag property of the model is changed to 1

assumptions: this function will be used asynchronously and only through keyboard depresses
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void quit_game(Model *model);

/*
=====================================================================================================================
purpose:     performs the movement functions on all player ships, helicopters, and jets if they
             are in play

input:       *players       -   the pointer to an array of Players, this is a 2 wide array
             *helicopters   -   the pointer to an array of helicopters, this is a 20 wide array
             *jets          -   the pointer to an array of jets, this is a 20 wide array

output:     positions       -   the position of all active ship objects on screen will have their positions altered
                                if they have corresponding directions set

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_ships(PlayerShip *players, Helicopter *helicopters, Jet *jets);
/*
=====================================================================================================================
purpose:  performs the movement functions on all player bullets, and bullets if they are 
          are in play

input:      *player_bullets   -       the pointer to an array of player bullets, this is a 50 wide array
            *bullets          -       the pointer to an array of bullets, this is a 50 wide array

output:     positions         -       the position of all active bullet objects on screen will have their positions altered
                                      to their corresponding directions set
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_bullets(PlayerBullet *player_bullets, Bullet *bullets);
/*
=====================================================================================================================
purpose:    performs the movement functions on all objects in the game if they are 
            are in play

input:      model       -   the pointer to the game's model, this houses all current game information

output:     positions   -   the position of all active objects on screen will have their positions altered
                            to their corresponding directions set

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void move_all(Model *model);
/*
=====================================================================================================================
purpose:  performs the shooting function for players if their fire_wep flag is true, ignores the 2nd
          ship if single player

input:      *players            -   the pointer to an array of players, that has a width of 2
            *bullets            -   the pointer to an array of player bullets, that has a width of 50 

output:     bullets             -   bullets will be pulled from the array to be played directly ahead of the 
                                    players ship, if already on the screen they will be ignored
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void players_shoot(PlayerShip *players, PlayerBullet *bullets);
/*
=====================================================================================================================
purpose:    performs the shooting functions of all objects on the screen, if they are in play, and
            if they are permitted to shoot

input:      model                   -   the pointer to the game's model, this houses all current game information

output:     bullets/player_bullets  -   bullets will be pulled from their arrays to be played directly ahead of the 
                                         players ship, or below the enemies. if already on the screen they will be ignored
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void shoot_bullets(Model *model);
/*
=====================================================================================================================
purpose: will check every helicopter on the game field for collisions with all player bullets on the game field 

input:          helicopters     -   the pointer to the array containing the helicopters
                bullets         -   the point to the array containing the player bullets

output:         player bullets  -   if collision occured, they will be removed from screen and returned to storage
                helicopters     -   if collision occured, they will enter a doomed state and explode, then despawn                
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: 
bugs:        
=====================================================================================================================
*/
void check_heliopter_hit(Helicopter *helicopters, PlayerBullet *bullets);
/*
=====================================================================================================================
purpose: will check jet helicopter on the game field for collisions with all player bullets on the game field 

input:          jets            -   the pointer to the array containing the jets
                bullets         -   the pointer to the array containing the player bullets

output:         player bullets  -   if collision occured, they will be removed from screen and returned to storage
                jets            -   if collision occured, they will enter a doomed state and explode, then despawn                  
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void check_jet_hit(Jet *jets, PlayerBullet bullets);
/*
=====================================================================================================================
purpose:     performs the collision detection functions on all enemies on the screen
             if they are in play

input:      model   -   the pointer to the model containing all game information

output:     helicopters -   if a helicopter is found to have a collision, it's collision property is changed to a 1   
            jets        -   if a jet is found to have a collision, it's collision property is changed to a 1
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void check_enemy_hit(Model *model);
/*
=====================================================================================================================
purpose:     will check players on the game field for collisions with enemy bullets

input:      player   -   the pointer to the array of players within the game
            bullets  -   the pointer to the array of enemy bullets within the game

output:     players  -   if a collision is detected on a player, the collsion property of that player will be changed to 1
            bullets  -   if an enemy bullet collides with a player, it is reverted to position of x = 1 and removed from playable region

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right) 
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void check_player_hit(PlayerShip *player, Bullet* bullets);
/*
=====================================================================================================================
purpose: check collisions of every single object in the playable area, and changes
         collision properties as is neccessary

input:      model       -   the pointer to the model of the game which houses all information      

output:     players     -   if a collision is detected on a player, the collsion property of that player will be changed to 1    
            helicopters -   if a helicopter is found to have a collision, it's collision property is changed to a 1   
            jets        -   if a jet is found to have a collision, it's collision property is changed to a 1
            bullets     -   if an enemy bullet collides with a player, it is reverted to position of x = 1 and removed from playable region
            Pbullets    -   if a player bullet collides with an enemy, it is reverted to position of x = 1 and removed from playable region

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)  
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void check_collisions(Model *model);
/*
=====================================================================================================================
purpose: process the "death state" of the players, facilitating its explosion and respawning

input:      player  -   pointer to the array of player ships

output:     player  -   death time may increase until 10, reset properties and respawn ship with one less life

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)  
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void destroy_player(PlayerShip *player);
/*
=====================================================================================================================
purpose:     process the "death state" of the helicopters, facilitating its explosion and respawning

input:      helicopters -   the pointer to the array of helicopters

output:     helicopters -   death time may increase until 10, reset properties and return to x = 1

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void destroy_helicopters(Helicopter *helicopters);
/*
=====================================================================================================================
purpose:     check all helicopters in playable area for weapon cooldown. fire if 0 and reset, or otherwise reduce by 1

input:      helicopters -   the pointer to the array of helicopters

output:     helicopters -   helicopters will have their cooldown properties altered when in playable area
            bullets     -   enemy bullets may spawn below helicopters     
assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void helicopters_shoot(Helicopter *helicopters, Bullet *bullets);
/*
=====================================================================================================================
purpose:     process the "death state" of the jets, facilitating its explosion and respawning


input:      jets    -   the pointer to the array of jets

output:     jets    -   death time may increase until 10, reset properties and return to x = 1

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void destroy_jets(Jet *jets);
/*
=====================================================================================================================
purpose:  process the death of all objects capable and meant to be dead that are in the playable area

input:      model       -   the pointer to the model of the game which houses all information     

output:     player  -   death time may increase until 10, reset properties and respawn ship with one less life
            jets    -   death time may increase until 10, reset properties and return to x = 1
            helicopters -   death time may increase until 10, reset properties and return to x = 1

assumptions: it is assumed that anything not in play is set either 0 (meaning that specific object has
             not been used yet, meaning there's nothing to its right) or set to 1 (meaning that specific
             object has been used before, so there's potentially more objects to the right)
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void destroy_all(Model *model);


#endif