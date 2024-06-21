#include "Enemy1.h"


IMAGE* Enemy1::getImg()
{
	return &enemy1Img;
}
IMAGE* Enemy1::freeImg()
{
	return &freedImg;
}
void Enemy1::setr(int r)
{
	random = r;
}
void Enemy1::setPos(Map* m)
{
	//srand(time(0));
	int x, y;
	do {
		 x = rand() % m->getCols();
		 y = rand() % m->getRows();
	} while (!m->accessible(x,y));
	pos.x = x;
	pos.y = y;
}

void Enemy1::action(ExMessage& msg, Map* m)
{
	
	beBlown(m);
	if (state == -1) { return; }
	if (state <= 20) {//slow down the speed of the enemy
		++state;
		return;
	}
	
	state= 1;
	m->setM(pos, 0);
	int dir = random % 4;
	switch (dir) {
	case 0:
		--pos.x;
		if (!m->accessible(getPos())) { ++pos.x; }
		break;
	case 1:
		--pos.y;
		if (!m->accessible(getPos())) { ++pos.y; }
		break;
	case 2:
		++pos.y;
		if (!m->accessible(getPos())) { --pos.y; }
		break;
	case 3:
		++pos.x;
		if (!m->accessible(getPos())) { --pos.x; }
		break;

	}
	m->setM(pos, -2);
}

Pos Enemy1::getPos()
{
	return pos;
}

int Enemy1::getX()
{
	return pos.x;
}

int Enemy1::getY()
{
	return pos.y;
}

void Enemy1::beBlown(Map* m)
{
	int s = m->searchM(pos.x, pos.y);
	if (s == -1) {
		state=-1;

	}
}

int Enemy1::getState()
{
	return state;
}


