#include "Enemy1.h"


IMAGE* Enemy1::getImg()
{
	return &enemy1Img;
}

void Enemy1::setPos(Map* m)
{
	srand(time(0));
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
	if (state < 20) {
		++state;
		return;
	}
	state = 1;
	srand(time(0));
	int dir = rand() % 4;
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
