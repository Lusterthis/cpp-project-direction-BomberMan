#pragma once
#include<vector>
#include<graphics.h>
#include<ctime>
#include<random>
//
#include "Pos.h"
#include"pch.h"
#include<graphics.h>

using namespace std;

enum Element {////////anything could be on the screen
	BOMB=-2,
	ENEMY=-1,
	NONOE=0,
	WALL=1,
	PLAYER=5
};
enum stage {

};
class Map
{
	/*class Player* p;*/
	int Rows,Cols;
	int marginX, marginY;
	int cellSize=30;//by default
	int level = 1;
	int bombnum=1;
	IMAGE PlayerImg;
	IMAGE BarrierImg;
	IMAGE BombImg1;
	IMAGE FireImg;
	IMAGE ENEMY1;
	IMAGE TacoImg;
	IMAGE BoxImg;
	vector<vector<int>>map;
	vector<vector<int>>status;
public:
	
	Map(int marginX, int marginY, int Cols, int Rows) {
		loadimage(&TacoImg, L"rsc/reanim/taco.png", cellSize, cellSize, true);
		loadimage(&BoxImg, L"rsc/reanim/box.png", cellSize, cellSize, true);
		this->marginX = marginX;
		this->marginY = marginY;
		this->Rows =Rows ;
		this-> Cols=Cols ;
		for (int i = 0; i < Cols; ++i) {
			vector<int>row;
			for (int j = 0; j < Rows; ++j) {
				row.push_back(0);
			}

			this->map.push_back(row);
		}
		map[0][0] = 5;
	}
	void Init();
	
	int getCols();
	int getRows();
	int getCellSize();
	int getLevel();
	vector<vector<int>>& getMap();
	void printMap(Pos pos);
	void setPlayer(int x,int y);//
	void setPlayer(Pos pos);//function overload;
	void leavePlayer(Pos pos);//
	double FormTransx(double n);
	double FormTransy(double n);
	bool accessible(int x,int y);
	bool accessible(Pos pos);
	bool is2(Pos pos);
	bool is2(int x, int y);
	bool ism2(int x, int y);
	void layBomb(Pos pos);
	void scene0();
	void scenex();
	void box();
	void taco();
	void BombBlow(int x,int y);
	int searchM(int x, int y);
	void setM(Pos pos,int g);
	void setM(int x, int y, int g);
};

