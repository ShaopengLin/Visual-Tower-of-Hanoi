#include "prototypesHanoi.h"
#include <apstring.cpp>
//draws the game interface
void drawDisplay(Peg &tower1, Peg &tower2, Peg &tower3)
{
    //al_draw_bitmap(ricardo,0,0,NULL);
    //draw background image
    al_draw_bitmap(ingameBackground,0,0,NULL);
    //draw all displays needed
    drawSolveButton();
    drawRingNumberChangeDisplay();
    drawPrecitionDisplay();
    drawStepCount();
    drawResetButton();
    drawTower(tower1);
    drawTower(tower2);
    drawTower(tower3);
    al_flip_display();
}
//draw the tower and the rings on it
void drawTower(Peg &tower)
{
    Ring *node = nullptr;
    //draws the base of the tower
    al_draw_filled_rounded_rectangle(tower.getPositionX(), tower.getPositionY(), tower.getPositionX()+RINGWIDTH, tower.getPositionY()+RINGHEIGHT,ROUND,ROUND,IRONBLACK);
    //draws the pole of the tower
    al_draw_rectangle(tower.getPositionX()+(RINGWIDTH/2-RINGHEIGHT/2), TOWERHEIGHT,tower.getPositionX()+(RINGWIDTH/2+RINGHEIGHT/2),tower.getPositionY(),IRONBLACK,10);
    //draws the rings from the bottom of the list
    for (node = tower.getBottomRing(); node != nullptr; node = node->previous) {
        al_draw_filled_rounded_rectangle(node->x, node->y, node->x + node->sizeX, node->y + node->sizeY, ROUND,ROUND,node->colour);
    }
}
//draw the graphics needed for user to change ring numbers
void drawRingNumberChangeDisplay()
{
    //draw the current ring number
    al_draw_text(farry, BLACK,TOWERGAP,TOWERGAP,NULL, std::to_string(Peg::getTotalRing()).c_str());
    //draw the square that contains the number
    al_draw_rectangle(TOWERGAP,TOWERGAP,2*TOWERGAP,2*TOWERGAP,BLACK,2);
    //draw the square for up button
    al_draw_rectangle(BUTTONPOSX, UPBUTTONPOSY, BUTTONPOSX+BUTTONSIZE, UPBUTTONPOSY+BUTTONSIZE,BLACK,2);
    //draw the triangle to show the up direction
    al_draw_filled_triangle(2*TOWERGAP+25,TOWERGAP,2*TOWERGAP+10,TOWERGAP+30,2*TOWERGAP+40,TOWERGAP+30,BLACK);
    //draw the square for down button
    al_draw_rectangle(BUTTONPOSX, DOWNBUTTONPOSY, BUTTONPOSX+BUTTONSIZE, DOWNBUTTONPOSY+BUTTONSIZE,BLACK,2);
    //draw the triangle to show the down direction
    al_draw_filled_triangle(2*TOWERGAP+10,2*TOWERGAP-30,2*TOWERGAP+40,2*TOWERGAP-30,2*TOWERGAP+25,2*TOWERGAP,BLACK);
}
//draws the minimum steps needed to win the game
void drawPrecitionDisplay()
{
    apstring text = "Minimum Step: ";
    //uses recursive function to find minimum steps
    text += std::to_string(predictMinimumStep(Peg::getTotalRing(), 1,3,2)).c_str();
    //draws the text
    al_draw_text(farry, BLACK,SCREENWIDTH/3,FONTSIZE, NULL, text.c_str());
}
//draws the solve button
void drawSolveButton()
{
    apstring text = "Solve";
    //draws the rectangle to hold the text
    al_draw_rectangle(SCREENWIDTH/3, SCREENHEIGHT/4,SCREENWIDTH/3+80,SCREENHEIGHT/4+32,BLACK, 2);
    //draws the text
    al_draw_text(mh, BLACK, SCREENWIDTH/3, SCREENHEIGHT/4, NULL, text.c_str());
}
//draws the reset button
void drawResetButton()
{
    apstring text = "Reset";
    //draws the rectangle that holds the text
    al_draw_rectangle(SCREENWIDTH/3+90, SCREENHEIGHT/4,SCREENWIDTH/3+170,SCREENHEIGHT/4+32,BLACK, 2);
    //draws the text
    al_draw_text(mh, BLACK, SCREENWIDTH/3+90, SCREENHEIGHT/4, NULL, text.c_str());
}
//draw the steps user has taken
void drawStepCount()
{
    apstring text = "Steps Taken: ";
    //extracts the step count from static variable in Peg class
    text += std::to_string(Peg::getStepsTaken()).c_str();
    //draw the text
    al_draw_text(farryHalfsize, BLACK, SCREENWIDTH/3+180, SCREENHEIGHT/4, NULL, text.c_str());
}
//draw instructions and title
void drawInstructionsTab()
{
    //al_draw_bitmap(elon,0,0,NULL);
    //draw background
    al_draw_bitmap(introBackground,0,0,NULL);
    apstring gameTitle = "Towers Of Hanoi";
    apstring instruction = "Try to get all the rings from the left tower to the right";
    apstring startGameinstruct = "Click to Start";
    //draw title text
    al_draw_text(titleFont, al_map_rgb(255,255,0), SCREENWIDTH/2, SCREENHEIGHT/2,ALLEGRO_ALIGN_CENTER, gameTitle.c_str());
    //draw instruction text
    al_draw_text(farryHalfsize, al_map_rgb(255,255,0), SCREENWIDTH/2,SCREENHEIGHT/2+FONTSIZE, ALLEGRO_ALIGN_CENTER,instruction.c_str());
    //draw start game instruction text
    al_draw_text(farryHalfsize,LIGHTBLUE,SCREENWIDTH/2,3*SCREENHEIGHT/4,ALLEGRO_ALIGN_CENTER,startGameinstruct.c_str());
    al_flip_display();
}

