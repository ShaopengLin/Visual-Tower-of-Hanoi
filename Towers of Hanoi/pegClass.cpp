#include "pegClass.h"
int Peg::totalRing = 0;
int Peg::stepsTaken = 7;
///constructor
Peg::Peg()
{
    head = nullptr;
    tail = nullptr;
    node = nullptr;
    positionX = 0;
    positionY = 0;
    numRing = 0;
}
///destructor
Peg::~Peg(){}
///push the given Ring onto the top of the peg's stack
Ring Peg::push(Ring *r)
{
    r->next = head;
    head = r;

    if (head->next == nullptr) {
        tail = head;
    } else {
        head->next->previous = head;
    }

    head->previous = nullptr;
    numRing++;
}
///removes and return the top of the ring from the peg's stack
Ring *Peg::pop()
{
    node = head;
    head = head->next;
    if(head != nullptr) {
        head->previous = nullptr;
    } else {
        tail = nullptr;
    }
    numRing--;

    return node;
}
///initialize the Rings in the peg based on the information in the peg class
void Peg::initializeRing()
{
    for (int i = totalRing; i >= 1; i--) {
        node = new Ring;
        node->ringSize = i;
        node->x = positionX+RINGWIDTH/2-RINGWIDTH*(1.0*node->ringSize/totalRing)/2;
        node->y = positionY-RINGHEIGHT*(totalRing-i+1);
        node->sizeX = RINGWIDTH*(1.0*node->ringSize/totalRing);
        node->sizeY = RINGHEIGHT;
        node->next = head;
        head = node;
        if (head->next == nullptr) {
            tail = head;
        } else {
            head->next->previous = head;
        }
    }
}
///refreshes the Peg's rings position information
void Peg::refreshRingsInfo()
{
    node = tail;
    for (int i = numRing; i >= 1; i--) {
        node->x = positionX+RINGWIDTH/2-RINGWIDTH*(1.0*node->ringSize/totalRing)/2;
        node->y = positionY-RINGHEIGHT*(numRing-i+1);
        node = node->previous;
    }
}
///set the number of the Ring in Peg with the given number and initialize the ring's information
void Peg::setNumRing(int numInput)
{
    totalRing = numInput;
    numRing = numInput;
    initializeRing();
}
///set the Peg's X position
void Peg::setPositionX(float posX)
{
    positionX = posX;
}
///set the Peg's Y position
void Peg::setPositionY(float posY)
{
    positionY = posY;
}
///move the top ring from one Peg to another
void Peg::moveRing(Peg &startTower, Peg &destTower)
{
    destTower.push(startTower.pop());
    //refresh both rings' information
    startTower.refreshRingsInfo();
    destTower.refreshRingsInfo();
    stepsTaken++;
}
///removes all the rings in the peg
void Peg::clearRingList()
{
    while (head != nullptr) {
        pop();
    }
}
///get the totalRing in all pegs
int Peg::getTotalRing()
{
    return totalRing;
}
///reset the steps
void Peg::resetStepsTaken()
{
    stepsTaken = 0;
}
///set the x coordinate of the top ring in the peg to the given value
void Peg::setTopRingX(int ringX)
{
    head->x = ringX;
}
///set the y coordinate of the top ring in the peg to the given value
void Peg::setTopRingY(int ringY)
{
    head->y = ringY;
}
///get how many steps are taken by the user that is stored in class
int Peg::getStepsTaken()
{
    return stepsTaken;
}
