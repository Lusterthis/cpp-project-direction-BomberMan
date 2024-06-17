#pragma once
#include"Dynamics.h"

 struct Pos{
	int x = 0, y = 0;
};

class Player:public Dynamics

{
private:
	Pos pos;

public:
	Player(int x, int y);
	void action (MSG &msg);
	bool destroy(Map* m);
	Pos getPos();//get the postion at the same time
};

