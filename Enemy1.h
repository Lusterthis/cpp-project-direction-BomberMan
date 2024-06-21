#pragma once
#include "Enemy.h"
class Enemy1 :
    public Enemy
{
private:
    Pos pos;
    IMAGE enemy1Img;
    IMAGE freedImg;
    int state=1;
    int random = 0;
public:
    Enemy1(Map *m) {
        setPos(m);
        int cellSize = m->getCellSize();
        loadimage(&enemy1Img, L"rsc/reanim/enemy1.png", cellSize, cellSize, true);
        loadimage(&freedImg, L"rsc/reanim/enemy1o.png", cellSize, cellSize, true);
    }
    void setr(int r);//set the random number;
    IMAGE* getImg();
    IMAGE* freeImg();
    void setPos(Map * m);
    void action(ExMessage& msg, Map* m);
    /////////////////////////////////////////////
    Pos getPos();
    int getX();
    int getY();
    void beBlown(Map* m);
    int getState();
  
};

