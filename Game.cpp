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
	//m->scene0();
	m->scenex();
	ExMessage msg ;
	Pos tmp;
	while (1) {

		/*m->setPlayer(p->getPos());*/
		bool b = peekmessage(&msg);//check cin stream while execute program

		while (b&&msg.message == WM_KEYDOWN&&msg.wParam == VK_SPACE) {
			system("pause");
		}

		
		if(b&&msg.message==WM_KEYDOWN)
		{
			
			p->action(msg,m);//change the postion of player or perform some act?
		}

		m->printMap(p->getPos());
		FlushBatchDraw();//print all the dynamics at the same time in case of flash;
		//printf(".");

		Sleep(16);
	}
}
