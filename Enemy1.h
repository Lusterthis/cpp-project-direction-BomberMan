#pragma once
#include "Enemy.h"
class Enemy1 :
    public Enemy
{
private:
    Pos pos;
    IMAGE enemy1Img;
    int state=1;
public:
    Enemy1(Map *m) {
        setPos(m);
        int cellSize = m->getCellSize();
        loadimage(&enemy1Img, L"rsc/reanim/enemy1.png", cellSize, cellSize, true);
    }
    IMAGE* getImg();
    void setPos(Map * m);
    void action(ExMessage& msg, Map* m);
    Pos getPos();
    int getX();
    int getY();
};

