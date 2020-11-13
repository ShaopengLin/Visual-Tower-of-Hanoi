#ifndef _prototypesHanoi_h_
#define _prototypesHanoi_h_
#include <iostream>
#include <apvector.h>
#include <apstring.h>
#include <string>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include "pegClass.h"

#define SCREENWIDTH 1300
#define SCREENHEIGHT 700
#define FONTNAMEFORFARRY "FARRAY.otf"
#define FONTNAMEFORMH "MH.ttf"
#define FONTNAMEFORTITLE "CHLORINP.ttf"
#define DEFAULTRINGNUMBER 3
#define MAXRINGNUMBER 10
#define FONTSIZE SCREENHEIGHT/10.9375
#define TOWERHEIGHT (3*SCREENHEIGHT/7)
#define RINGHEIGHT 30
#define ROUND (RINGHEIGHT/2)
#define RINGWIDTH SCREENWIDTH/4
#define TOWERGAP SCREENWIDTH/16
#define BACKGROUNDCOLOR al_map_rgb(255, 255, 255)
#define LIGHTBLUE al_map_rgb(135,206,250)
#define IRONBLACK al_map_rgb(67,75,77)
#define BLACK al_map_rgb(0,0,0)
#define BUTTONPOSX (2*TOWERGAP+10)
#define UPBUTTONPOSY TOWERGAP
#define DOWNBUTTONPOSY (2*TOWERGAP-30)
#define BUTTONSIZE 30

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_FONT *farry;
extern ALLEGRO_FONT *mh;
extern ALLEGRO_FONT *farryHalfsize;
extern ALLEGRO_FONT *titleFont;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_BITMAP *ricardo;
extern ALLEGRO_BITMAP *introBackground;
extern ALLEGRO_BITMAP *ingameBackground;
extern ALLEGRO_BITMAP *elon;

int initializeAllegro();
int destroyAllegro();
int predictMinimumStep(int numRing, int source, int dest, int mid);
void drawDisplay(Peg &tower1,Peg &tower2,Peg &tower3);
void drawTower(Peg &tower);
void drawRingNumberChangeDisplay();
void drawPrecitionDisplay();
void hanoi(int numRing, Peg &source, Peg &dest, Peg &mid);
void initializeTowers(int ringNum, apvector<Peg> &tower);
void increaseRingNumber(apvector<Peg> &tower);
void decreaseRingNumber(apvector<Peg> &tower);
void drawSolveButton();
void drawResetButton();
void drawStepCount();
void drawInstructionsTab();
void ringMovement(Peg &tower,ALLEGRO_EVENT events);
bool addRingButtonPressed(ALLEGRO_MOUSE_STATE mouState);
bool removeRingButtonPressed(ALLEGRO_MOUSE_STATE mouState);
bool solveButtonPressed(ALLEGRO_MOUSE_STATE mouState);
bool resetButtonPressed(ALLEGRO_MOUSE_STATE mouState);
bool ringPressed(ALLEGRO_MOUSE_STATE mouState, Peg &tower);
bool towerHitbox(Peg &sourceTower, Peg &destTower);
bool screenHitboxX(Peg &tower, ALLEGRO_EVENT events);
bool screenHitboxY(Peg &tower, ALLEGRO_EVENT events);


#endif
