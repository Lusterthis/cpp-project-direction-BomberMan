#include "Player.h"



void Player::action(ExMessage& msg,Map *m)
{
	
	//m->leavePlayer(getPos());
		switch (msg.vkcode) {
		case VK_UP:
			--pos.y;
			if (!m->accessible(getPos())) { ++pos.y; }
				break;
		case VK_DOWN:
			++pos.y;//这个加减容易搞错
			if (!m->accessible(getPos())) { --pos.y; }
				break;
		case VK_LEFT:
			--pos.x;
			if (!m->accessible(getPos())) { ++pos.x; }
				break;
		case VK_RIGHT:
			++pos.x;
			if (!m->accessible(getPos())) { --pos.x; }
			break;
		//case VK_MENU://alt key

		//	m->layBomb(pos);
		//	break;
		}
		
}



Pos Player::getPos()
{
	return pos;
}

IMAGE* Player::getImg()
{
	if (status < 5) {
		++status;
		return &player1Img;
	}
	else if (status < 10) {
		++status;
		return &player2Img;
	}
	else if (status < 15) {
		++status;
		return &player3Img;
	}
	else if(status<18){
		++status;
	    return &player4Img;
	}
	else if (status < 20) {
		++status;
		return &player3Img;
	}
	else {
		status = 0;
		return &player2Img;
	}
	
	
}

int Player::getX()
{
	return pos.x;
}

int Player::getY()
{
	return pos.y;
}

int Player::getLevel()
{
	return level;
}

void Player::setLevel(int l)
{
	level = l;
}
