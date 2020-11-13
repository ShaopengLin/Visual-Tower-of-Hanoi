#include "prototypesHanoi.h"
#ifndef _pegClass_h_
#define _pegClass_h_
struct Ring {
    int ringSize;
    //random colour
    ALLEGRO_COLOR colour = al_map_rgb(rand()%256,rand()%256,rand()%256);
    float x;
    float y;
    float sizeX;
    float sizeY;
    Ring *next = nullptr;
    Ring *previous = nullptr;
};
class Peg
{
    private:
        Ring *head;
        Ring *tail;
        Ring *node;
        float positionX;
        float positionY;
        static int totalRing;
        static int stepsTaken;
        int numRing;
    public:
        Peg();
        ~Peg();
        ///get the linked list in this peg
        inline Ring *getTopRing()
        {
            return head;
        }
        ///get the bottom of the list in this peg
        inline Ring *getBottomRing()
        {
            return tail;
        }
        ///get the Peg's current x position
        inline float getPositionX()
        {
            return positionX;
        }
        ///get the Peg's current y position
        inline float getPositionY()
        {
            return positionY;
        }
        ///get the number of rings in this peg
        inline int getNumRing()
        {
            return numRing;
        }
        void setNumRing(int numInput);
        void setPositionX(float posX);
        void setPositionY(float posY);
        void initializeRing();
        Ring push(Ring *r);
        Ring *pop();
        void clearRingList();
        static void moveRing(Peg &startTower, Peg &destTower);
        static void resetStepsTaken();
        static int getTotalRing();
        static int getStepsTaken();
        void refreshRingsInfo();
        void setTopRingX(int ringX);
        void setTopRingY(int ringY);
};
#endif
