#pragma once
#include "Dynamics.h"
class Bomb :
    public Dynamics
{
private:
    int status = 0;
    Pos pos;
    IMAGE bomb1Img;
    IMAGE bomb2Img;
    IMAGE bomb3Img;
    IMAGE bomb4Img;
    IMAGE fire1Img;
    IMAGE fire2Img;
public:
    Bomb(Pos posn,int cellSize) {
        pos.x = posn.x;
        pos.y = posn.y;
        loadimage(&bomb1Img, L"rsc/reanim/Cherrybomb1.png", cellSize, cellSize, true);
        loadimage(&bomb2Img, L"rsc/reanim/Cherrybomb2.png", cellSize, cellSize, true);
        loadimage(&bomb3Img, L"rsc/reanim/Cherrybomb3.png", cellSize, cellSize, true);
        loadimage(&bomb4Img, L"rsc/reanim/Cherrybomb4.png", cellSize, cellSize, true);
        loadimage(&fire1Img, L"rsc/reanim/fire1.png", cellSize, cellSize, true);
        loadimage(&fire2Img, L"rsc/reanim/fire2.png", cellSize, cellSize, true);
   }
    void action(ExMessage& msg, Map* m);
    void setPos(Pos posn);
    void blowUp(Map * m,int level);
    IMAGE* getImg();
    IMAGE* getImg2();
    int getX();
    int getY();
    Pos getPos();
    int getStatus();

};

