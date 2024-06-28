#pragma once
#include"Player.h"
#include"Map.h"
#include<Windows.h>
#include"Enemy1.h"
#include"Bomb.h"


#include<vector>
class Game
{
public:
	Game(Map* m,Player* p);
	void play();
	
private:
	Map* m;
	Player* p;
	vector<Bomb*> bag;//store your bombs
	int enemyNum;
};

