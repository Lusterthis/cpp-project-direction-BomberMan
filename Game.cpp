#include "Game.h"


enum initState {
	menu,
	playing
};

Game::Game(Map* m,Player* p)
{
	this->m = m;
	this->p = p;

	;
}

void Game::play()
{
	m->Init();
	srand(time(0));

	//m->scene0();
	m->scenex();
	ExMessage msg ;
	vector<Bomb*> bag;
	int Enemynum = 5 * m->getLevel();
	vector<Enemy1*> e1(Enemynum);
	for (int i = 0; i <Enemynum;++i) {
		Enemy1* e = new Enemy1(m);
		e1.push_back(e);
		
	}
	Pos tmp;
	while (1) {

		/*m->setPlayer(p->getPos());*/
		bool b = peekmessage(&msg);//check cin stream while execute program

		if(b&&msg.message == WM_KEYDOWN&&msg.vkcode == VK_SPACE) {

			system("pause");
		}

		
		if(b&&msg.message==WM_KEYDOWN)
		{

			p->action(msg,m);//change the postion of player or perform some act?
			if (msg.vkcode == VK_MENU) {
				Bomb* bomb = new Bomb(p->getPos(), m->getCellSize());
				bag.push_back(bomb);
			}
		}

		m->printMap(p->getPos());

		//putimagePNG;
		if(!bag.empty())
		for (Bomb* bomb : bag) {
			//if (bomb == nullptr) { continue; }
			if (bomb->getStatus() == -1) {
				//bag.erase(bomb);
				//delete bomb;
				continue;
			}
			bomb->putimagePNG(m->FormTransx(bomb->getX()), m->FormTransy(bomb->getY()), bomb->getImg());
			if (bomb->getStatus() > 15) {
				for (int i = 1; i <= p->getLevel(); ++i) {
					bomb->putimagePNG(m->FormTransx(bomb->getX()+i), m->FormTransy(bomb->getY()), bomb->getImg2());
					bomb->putimagePNG(m->FormTransx(bomb->getX()-i), m->FormTransy(bomb->getY()), bomb->getImg2());
					bomb->putimagePNG(m->FormTransx(bomb->getX()), m->FormTransy(bomb->getY()+i), bomb->getImg2());
					bomb->putimagePNG(m->FormTransx(bomb->getX()), m->FormTransy(bomb->getY()-i), bomb->getImg2());
				}
			}
		}
		int tmp = 0;
		for (Enemy1* e : e1) {
			
			if (e == nullptr) { continue; }
			
			if (1) {
				e->setr(rand());
				++tmp;
				e->action(msg, m);
				e->putimagePNG(m->FormTransx(e->getX()), m->FormTransy(e->getY()), e->getImg());
			}
		}
		
		p->putimagePNG(m->FormTransx(p->getX()), m->FormTransy(p->getY()), p->getImg());
		
		FlushBatchDraw();//print all the dynamics at the same time in case of flash;
		

		Sleep(16);
	}
}
