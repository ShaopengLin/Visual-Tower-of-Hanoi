// Towers Of Hanoi   Chris Lin   ICS4U  April 29, 2019   Lindsay Cullum
//Towers of Hanoi is a game where the user have to move the rings from the left most tower to the right
//User cannot put a ring on top of another ring that is bigger and can only access the first ring on the pile
//#NOTE: When user presses the solve button, no other operations can be made until finished
#include "prototypesHanoi.h"
using namespace std;
ALLEGRO_DISPLAY *display;
ALLEGRO_FONT *farry;
ALLEGRO_FONT *farryHalfsize;
ALLEGRO_FONT *mh;
ALLEGRO_FONT *titleFont;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_BITMAP *ricardo;
ALLEGRO_BITMAP *introBackground;
ALLEGRO_BITMAP *ingameBackground;
ALLEGRO_BITMAP *elon;

int main ()
{
    srand(time(NULL));
    //initialize Allegro functions
    initializeAllegro();
    //initialize the 3 towers, Peg class
    apvector<Peg> tower(3);
    //initialize the three tower with default information
    initializeTowers(DEFAULTRINGNUMBER, tower);
    //variable that tells if a ring is being moved by user and which tower is it from
    int pressedRingTowerNum = -1;
    //create event variables
    ALLEGRO_EVENT events;
    ALLEGRO_MOUSE_STATE mouState;
    //displays the opening screen
    while(true) {
        //draw instructions and title
        drawInstructionsTab();
        //start events
        al_get_mouse_state(&mouState);
        al_wait_for_event(event_queue, &events);
        //close the game when click close
        if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            //destroy created allegro variables
            destroyAllegro();
            return 0;
        }
        //if user clicks, enter game
        if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN & 1) {
            break;
        }
    }
    //game starts
    while (true) {
        //draws the game interface
        drawDisplay(tower[0],tower[1],tower[2]);
        //start events
        al_get_mouse_state(&mouState);
        al_wait_for_event(event_queue, &events);
        //close the game when click close
        if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            //destroy created allegro variables
            destroyAllegro();
            return 0;
        }
        //when user clicks the mouse, check if the user clicked a top most ring, if so, user can move it with a mouse
        if (al_mouse_button_down(&mouState, mouState.buttons & 1)) {
            for (int towerNum = 0; towerNum < tower.length(); towerNum++) {
                //hitbox
                if(ringPressed(mouState,tower[towerNum])) {
                    if (pressedRingTowerNum == -1 || towerNum == pressedRingTowerNum) {
                        //moves pressed ring with mouse
                        ringMovement(tower[towerNum], events);
                        pressedRingTowerNum = towerNum;
                    }
                }
            }
        }
        //when user releases the mouse button
        if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP & 1) {
            //determine if the ring is pressed and the ring's destination based on its released position
            if(pressedRingTowerNum >= 0 && pressedRingTowerNum <= 2) {
                for (int towerNum = 0; towerNum < tower.length(); towerNum++) {
                    //hitbox
                    if (towerHitbox(tower[pressedRingTowerNum], tower[towerNum])) {
                        if (tower[towerNum].getTopRing() == nullptr ||
                                tower[pressedRingTowerNum].getTopRing()->ringSize < tower[towerNum].getTopRing()->ringSize) {
                            //moves the ring to the tower
                            Peg::moveRing(tower[pressedRingTowerNum],tower[towerNum]);
                            pressedRingTowerNum = -1;
                            break;
                            //returns the ring to original spot if it is in the same tower hitbox
                        } else if(towerNum == pressedRingTowerNum) {
                            tower[pressedRingTowerNum].refreshRingsInfo();
                            pressedRingTowerNum = -1;
                            break;
                        }
                    }
                }
                //returns the ring to original spot if it is in none of the towers' hitbox
                if(pressedRingTowerNum != -1) {
                    tower[pressedRingTowerNum].refreshRingsInfo();
                    pressedRingTowerNum = -1;
                }
                //add a ring if user released mouse on add button
            }
            else if(addRingButtonPressed(mouState)) {
                increaseRingNumber(tower);
                //remove a ring if user released mouse on decrease button
            } else if(removeRingButtonPressed(mouState)) {
                decreaseRingNumber(tower);
                //solve the game automatically if user released mouse on solve button
            } else if(solveButtonPressed(mouState)) {
                //reset the game
                initializeTowers(Peg::getTotalRing(), tower);
                //uses recursive method
                hanoi(Peg::getTotalRing(),tower[0],tower[2],tower[1]);
                //reset the game if user released mouse on reset button
            } else if(resetButtonPressed(mouState)) {
                initializeTowers(Peg::getTotalRing(), tower);
            }
        }

    }
}



