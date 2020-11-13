#include "prototypesHanoi.h"
//hit box for add ring button
bool addRingButtonPressed(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= BUTTONPOSX && mouState.y >= UPBUTTONPOSY && mouState.x <= BUTTONPOSX+BUTTONSIZE && mouState.y <= UPBUTTONPOSY+BUTTONSIZE) {
        return true;
    }
    return false;
}
//hit box for remove ring button
bool removeRingButtonPressed(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= BUTTONPOSX && mouState.y >= DOWNBUTTONPOSY && mouState.x <= BUTTONPOSX+BUTTONSIZE && mouState.y <= DOWNBUTTONPOSY+BUTTONSIZE) {
        return true;
    }
    return false;
}
//hit box for solve button
bool solveButtonPressed(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= SCREENWIDTH/3 && mouState.y >= SCREENHEIGHT/4 && mouState.x <= SCREENWIDTH/3+80 && mouState.y <= SCREENHEIGHT/4+32) {
        return true;
    }
    return false;
}
//hit box for reset button
bool resetButtonPressed(ALLEGRO_MOUSE_STATE mouState)
{
    if (mouState.x >= SCREENWIDTH/3+90 && mouState.y >= SCREENHEIGHT/4 && mouState.x <= SCREENWIDTH/3+170 && mouState.y <= SCREENHEIGHT/4+32) {
        return true;
    }
    return false;
}
//hit box for rings
bool ringPressed(ALLEGRO_MOUSE_STATE mouState, Peg &tower)
{
    if (tower.getTopRing() != nullptr) {
        if(mouState.x >= tower.getTopRing()->x && mouState.y >= tower.getTopRing()->y &&
                mouState.x <= tower.getTopRing()->x + tower.getTopRing()->sizeX && mouState.y <= tower.getTopRing()->y + tower.getTopRing()->sizeY) {
            return true;
        }
    }
    return false;
}
//hit box for a tower
bool towerHitbox(Peg &sourceTower, Peg &destTower)
{
    if(sourceTower.getTopRing()->x+sourceTower.getTopRing()->sizeX/2 >= destTower.getPositionX() && sourceTower.getTopRing()->y >= destTower.getPositionY()-TOWERHEIGHT &&
            sourceTower.getTopRing()->x+sourceTower.getTopRing()->sizeX/2<= destTower.getPositionX() + RINGWIDTH &&
            sourceTower.getTopRing()->y + sourceTower.getTopRing()->sizeY <= destTower.getPositionY()+RINGHEIGHT
      ) {

        return true;
    }
    return false;
}
//hit box for the screen's X coordinate
bool screenHitboxX(Peg &tower, ALLEGRO_EVENT events){
    if (tower.getTopRing()->x+events.mouse.dx > 0 && tower.getTopRing()->x+tower.getTopRing()->sizeX+events.mouse.dx < SCREENWIDTH){
        return true;
    }
    return false;
}
//hit box for the screen's Y coordinate
bool screenHitboxY(Peg &tower, ALLEGRO_EVENT events){
    if (tower.getTopRing()->y+events.mouse.dy > 0 && tower.getTopRing()->y+tower.getTopRing()->sizeY+events.mouse.dy < SCREENHEIGHT){
        return true;
    }
    return false;
}
