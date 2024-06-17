#pragma once
#include"Player.h"
#include"Map.h"
#include<Windows.h>
class Game
{
public:
	Game(Map* m,Player* p);
	void play();

private:
	Map* m;
	Player* p;

};

