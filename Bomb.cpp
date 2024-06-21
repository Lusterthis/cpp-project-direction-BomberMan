#include "Bomb.h"

void Bomb::action(ExMessage& msg, Map* m)
{
}

void Bomb::setPos(Pos posn)
{
	pos.x = posn.x;
	pos.y = posn.y;
}

void Bomb::blowUp()
{


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
	
	else {//
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
