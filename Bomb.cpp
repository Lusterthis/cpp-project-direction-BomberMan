#include "Bomb.h"

void Bomb::action(ExMessage& msg, Map* m)
{
}

void Bomb::setPos(Pos posn)
{
	pos.x = posn.x;
	pos.y = posn.y;
}

void Bomb::blowUp(Map* m,int level)
{
	for (int i = 1; i <= level; ++i) {
		if (status  > 15&&status<45) {
			m->setM(pos, -1);
			m->setM(pos.x + i, pos.y, -1);
			m->setM(pos.x - i, pos.y, -1);
			m->setM(pos.x, pos.y + i, -1);
			m->setM(pos.x, pos.y - i, -1);
		
		}
		else if (status>=45) {
			m->setM(pos, 0);
			m->setM(pos.x + i, pos.y, 0);
			m->setM(pos.x - i, pos.y, 0);
			m->setM(pos.x, pos.y + i, 0);
			m->setM(pos.x, pos.y - i, 0);
		}
	}
}

IMAGE* Bomb::getImg()
{
	if (status < 5) {
		++status;
		return &bomb1Img;
	}
	else if (status < 10) {
		++status;
		return &bomb2Img;
	}
	else if (status < 15) {
		++status;
		return &bomb3Img;
	}
	else if (status < 45) {
		++status;
		return &bomb4Img;
	}
	
	else {//=45
		status = -1;
		return &bomb4Img;
	}


}

IMAGE* Bomb::getImg2()
{
	int s = status % 20;
	if (s < 10) {
		return &fire1Img;
	}
	else {
		return &fire2Img;
	}
}

int Bomb::getX()
{
	return pos.x;
}

int Bomb::getY()
{
	return pos.y;
}

Pos Bomb::getPos()
{
	return pos;
}

int Bomb::getStatus()
{
	return status;
}
