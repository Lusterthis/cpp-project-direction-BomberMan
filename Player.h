#pragma once
#include"Dynamics.h"


class Player:public Dynamics

{
private:
	Pos pos;

public:
	Player(int x, int y);
	void action (ExMessage &msg,Map * m);
	bool destroy(Map* m);
	Pos getPos();//get the postion at the same time


	int getX();
	int getY();
};

