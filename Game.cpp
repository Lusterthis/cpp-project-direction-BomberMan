#include "Game.h"




Game::Game(Map* m,Player* p)
{
	this->m = m;
	this->p = p;

	
}

void Game::play()
{
	mciSendString(L"play rsc/bgm/lawnbgm.mp3", 0, 0, 0);
	//play video
	m->Init();
	srand(time(0));

	m->scene0();
	//m->scenex();
	m->box();
	ExMessage msg ;
	vector<Bomb*> bag;
	int Enemynum = 5 * m->getLevel();
	vector<Enemy1*> e1;
	for (int i = 0; i <Enemynum;++i) {
		Enemy1* e = new Enemy1(m);
		e1.push_back(e);
		
	}
	m->taco();
	while (1&&!p->fail()) {

		/*m->setPlayer(p->getPos());*/
		bool b = peekmessage(&msg);//check cin stream while execute program

		if(b&&msg.message == WM_KEYDOWN&&msg.vkcode == VK_SPACE) {
			mciSendString(L"pause rsc/bgm/lawnbgm.mp3", 0, 0, 0);
			system("pause");
			
			//Sleep(3000);
			mciSendString(L"resume rsc/bgm/lawnbgm.mp3", 0, 0, 0);
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
			if (bomb->getStatus() == -1) {
				continue;
			}
			else if (bomb->getStatus() >= 0) {
				bomb->putimagePNG(m->FormTransx(bomb->getX()), m->FormTransy(bomb->getY()), bomb->getImg());
				if (bomb->getStatus() > 45) {//until 45
					for (int i = 1; i <= p->getLevel(); ++i) {
						bomb->putimagePNG(m->FormTransx(bomb->getX() + i), m->FormTransy(bomb->getY()), bomb->getImg2());
						bomb->putimagePNG(m->FormTransx(bomb->getX() - i), m->FormTransy(bomb->getY()), bomb->getImg2());
						bomb->putimagePNG(m->FormTransx(bomb->getX()), m->FormTransy(bomb->getY() + i), bomb->getImg2());
						bomb->putimagePNG(m->FormTransx(bomb->getX()), m->FormTransy(bomb->getY() - i), bomb->getImg2());
						bomb->blowUp(m,i);
					}
				}
			}
		}
		int tmp = 0;
		for (Enemy1* e : e1) {
			
			if (e->getState()==0) { continue; }
			
			if (e->getState() >= 1) {
				e->setr(rand());
				++tmp;
				e->action(msg, m);//start acting,but there is possiblity that e jumps to fire
				if (1) {
					e->putimagePNG(m->FormTransx(e->getX()), m->FormTransy(e->getY()), e->getImg());
				}
			}
			 if (e->getState() <= -1) {
				e->putimagePNG(m->FormTransx(e->getX()), m->FormTransy(e->getY()), e->freeImg());
			}
		}
		
		p->putimagePNG(m->FormTransx(p->getX()), m->FormTransy(p->getY()), p->getImg());
		p->beBlown(m);
		FlushBatchDraw();//print all the dynamics at the same time in case of flash;
		

		Sleep(16);
	}
	mciSendString(L"close rsc/bgm/lawnbgm.mp3", 0, 0, 0);
	if (p->fail()) {
		
		p->loserdraw(m);
	}
}
