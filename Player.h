#pragma once
#include"Dynamics.h"


class Player:public Dynamics

{
private:
	Pos pos;
	int status = 0;
	IMAGE player1Img;
	IMAGE player2Img;
	IMAGE player3Img;
	IMAGE player4Img;

	
	int level = 1;
	int lives = 3;
public:
	Player(int x, int y,int cellSize) {
		loadimage(&player1Img, L"rsc/reanim/player1.png", cellSize, cellSize, true);
		loadimage(&player2Img, L"rsc/reanim/player2.png", cellSize, cellSize, true);
		loadimage(&player3Img, L"rsc/reanim/player3.png", cellSize, cellSize, true);
		loadimage(&player4Img, L"rsc/reanim/player4.png", cellSize, cellSize, true);
		loadimage(&loserImg, L"rsc/lose.jpg", 775, 394, true);
	};
	void action (ExMessage &msg,Map * m);
	//bool destroy(Map* m);
	Pos getPos();//get the postion at the same time

	IMAGE loserImg;

	IMAGE* getImg();
	IMAGE* getImg1();//±∏”√
	int getX();
	int getY();
	int getLevel();
	void setLevel(int l);
	void beBlown(Map* m);
	bool fail();
	void loserdraw(Map* m);
};

