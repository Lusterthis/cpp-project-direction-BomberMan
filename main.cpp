#include<iostream>
#include"Game.h"

int main() {
	Player p(0,0);
	Map grass(257, 86, 30, 10);
	Game game(&grass,&p);
	game.play();
}