#include "Game.h"

Game::Game(Map* m,Player* p)
{
	this->m = m;
	this->p = p;

	;
}

void Game::play()
{
	m->Init();
	MSG msg;
	while (1) {

		//m->setPlayer(p->getPos());
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);//check cin stream while execute program
		if (msg.message == VK_SPACE) {
			system("pause");
		}
		p->action(msg);
		m->printMap();
		
		Sleep(16);
	}
}
