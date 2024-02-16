#include <osbind.h>
#include "RENDERER.H"
#include "RASTER.H"
#include "TYPES.H"



int main(){
    Model the_model;
    the_model.ship[0].position.x = 300;
    the_model.ship[0].position.y = 350;

    the_model.playerBullets[0].position.x = 300;
    the_model.playerBullets[0].position.y = 318;
    the_model.playerBullets[1].position.x = 310;
    the_model.playerBullets[1].position.y = 290;
    the_model.playerBullets[2].position.x = 290;
    the_model.playerBullets[2].position.y = 270;

    the_model.helicopters[0].position.x = 100;
    the_model.helicopters[0].position.y = 100;
    the_model.helicopters[1].position.x = 500;
    the_model.helicopters[1].position.y = 100;
    the_model.helicopters[2].position.x = 200;
    the_model.helicopters[2].position.y = 200;
    the_model.helicopters[3].position.x = 440;
    the_model.helicopters[3].position.y = 200;

    the_model.jets[0].position.x = 320;
    the_model.jets[0].position.y = 50;
    

    the_model.bullets[0].position.x = 120;
    the_model.bullets[0].position.y = 141;
    the_model.bullets[1].position.x = 490;
    the_model.bullets[1].position.y = 141;
    the_model.bullets[2].position.x = 230;
    the_model.bullets[2].position.y = 261;
    the_model.bullets[3].position.x = 410;
    the_model.bullets[3].position.y = 261;
    
    the_model.powerup.position.x = 310;
    the_model.powerup.position.y = 250;

    the_model.score.total =56374;
    the_model.score.position.x = 10;
    the_model.score.position.y = 100;



    render(&(the_model));
    return 0;
}
