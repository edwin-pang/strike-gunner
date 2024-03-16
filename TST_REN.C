#include <osbind.h>
#include "RENDERER.H"
#include "RASTER.H"
#include "TYPES.H"


Model model;
int main(){
    model.ship[0].position.x = 300;
    model.ship[0].position.y = 350;

    model.playerBullets[0].position.x = 300;
    model.playerBullets[0].position.y = 318;
    model.playerBullets[1].position.x = 310;
    model.playerBullets[1].position.y = 290;
    model.playerBullets[2].position.x = 290;
    model.playerBullets[2].position.y = 270;

    model.enemies[0].position.x = 100;
    model.enemies[0].position.y = 100;
    model.enemies[1].position.x = 500;
    model.enemies[1].position.y = 100;
    model.enemies[2].position.x = 200;
    model.enemies[2].position.y = 200;
    model.enemies[3].position.x = 440;
    model.enemies[3].position.y = 200;

    model.enemies[0].position.x = 320;
    model.enemies[0].position.y = 50;
    

    model.bullets[0].position.x = 120;
    model.bullets[0].position.y = 141;
    model.bullets[1].position.x = 490;
    model.bullets[1].position.y = 141;
    model.bullets[2].position.x = 230;
    model.bullets[2].position.y = 261;
    model.bullets[3].position.x = 410;
    model.bullets[3].position.y = 261;
    
    model.powerup.position.x = 310;
    model.powerup.position.y = 250;

    model.score.total =56374;
    model.score.position.x = 10;
    model.score.position.y = 100;

    model.lives.health_bar = 3;
    model.lives.position.x = 10;
    model.lives.position.y = 150;

    render(&(model), Physbase());
    return 0;
}
