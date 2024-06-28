#include<iostream>
#include"Game.h"
#include"Menu.h"

int main() {
	Setting set;

	while (1) {
		Menu menu(&set);
		menu.display();


		Map grass(&set);//257,86,30,15by default
		Player p(0, 0, grass.getCellSize());
		Game game(&grass, &p);

		game.play();

	}

}