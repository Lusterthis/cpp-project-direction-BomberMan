#pragma once
#include<vector>
#include<graphics.h>
//
#include "Pos.h"
#include<ctime>
#include<random>
using namespace std;

enum Type {
	BOMB=-2,
	ENEMY=-1,
	NONOE=0,
	WALL=1,
	PLAYER=5
};
class Map
{
	/*class Player* p;*/
	int Rows,Cols;
	int marginX, marginY;
	int cellSize=35;//by default
	IMAGE PlayerImg;
	IMAGE BarrierImg;
	IMAGE BombImg1;
	IMAGE FireImg;
	IMAGE ENEMY1;
	vector<vector<int>>map;
public:
	
	Map(int marginX, int marginY, int Cols, int Rows) {
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
	vector<vector<int>>& getMap();
	void printMap(Pos pos);
	void setPlayer(int x,int y);
	void setPlayer(Pos pos);//function overload;
	void leavePlayer(Pos pos);
	double FormTransx(double n);
	double FormTransy(double n);
	bool accessible(int x,int y);
	bool accessible(Pos pos);
	void layBomb(Pos pos);
	void scene0();
	void scenex();
	
};

