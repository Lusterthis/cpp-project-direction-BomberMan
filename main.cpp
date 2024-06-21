#include<iostream>
#include"Game.h"

int main() {
	
	Map grass(257, 86, 30, 10);
	Player p(0, 0,grass.getCellSize());
	Game game(&grass,&p);
	
	game.play();
}