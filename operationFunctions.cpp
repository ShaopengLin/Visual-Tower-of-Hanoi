#include "prototypesHanoi.h"
//recursive function similar to hanoi that returns the minimum step needed to move the given ring number to the right
int predictMinimumStep(int numRing, int source, int dest, int mid)
{
    int minStep = 0;
    if (numRing > 0) {
        minStep++;
        //the recursive functions will return their relative steps
        minStep += predictMinimumStep(numRing-1,source,mid,dest);
        minStep += predictMinimumStep(numRing-1,mid,dest,source);
    }
    return minStep;
}
//recursively moves the rings from the left most tower to the right (step by step)
void hanoi(int numRing, Peg &source, Peg &dest, Peg &mid)
{
    if (numRing > 0) {
        hanoi(numRing-1,source,mid,dest);
        //moves the top ring from source tower to the destination tower
        Peg::moveRing(source, dest);
        //refreshes the display with changed information
        drawDisplay(source, mid, dest);
        //wait a while for user to interpret
        al_rest(0.2);
        hanoi(numRing-1,mid,dest,source);
    }
}
//initialize the three tower with given information
void initializeTowers(int ringNum, apvector<Peg> &tower)
{
    for (int i = 0; i < 3; i++) {
        //clears the linked list in the peg
        tower[i].clearRingList();
        //reset the positions of the towers
        tower[i].setPositionX((i)*(RINGWIDTH)+(i+1)*TOWERGAP);
        tower[i].setPositionY(6*SCREENHEIGHT/7);
    }
    //set all the rings to the left most tower
    tower[0].setNumRing(ringNum);
    //refreshes the steps taken by the user
    Peg::resetStepsTaken();
}
//increases the total ring number by 1
void increaseRingNumber(apvector<Peg> &tower)
{
    //up to maximum ring number
    if(Peg::getTotalRing()+1 <= MAXRINGNUMBER) {
        //initialize the towers with one more ring
        initializeTowers(Peg::getTotalRing()+1,tower);
    }
}
//decrease the total ring number by 1
void decreaseRingNumber(apvector<Peg> &tower)
{
    //down to minimum ring number
    if(Peg::getTotalRing()-1 >= DEFAULTRINGNUMBER) {
        //initialize the towers wit one less ring
        initializeTowers(Peg::getTotalRing()-1,tower);
    }
}
//moves pressed ring with mouse
void ringMovement(Peg &tower, ALLEGRO_EVENT events)
{
    //moves the ring by the mouse's X displacement, if at the right or left most end, do nothing
    if (screenHitboxX(tower,events)) {
        tower.setTopRingX(tower.getTopRing()->x+events.mouse.dx);
    }
    //moves the ring by the mouse's Y displacement, if at the top or bottom, do nothing
    if (screenHitboxY(tower,events)) {
        tower.setTopRingY(tower.getTopRing()->y+events.mouse.dy);
    }
}
