#include "Player.h"



void Player::action(ExMessage& msg,Map *m)
{
	
	//m->leavePlayer(getPos());
		switch (msg.vkcode) {
		case VK_UP:
			--pos.y;
			if (!m->accessible(getPos())&&!m->ism2(pos.x,pos.y)) { ++pos.y; }
				break;
		case VK_DOWN:
			++pos.y;//这个加减容易搞错
			if (!m->accessible(getPos()) && !m->ism2(pos.x, pos.y)) { --pos.y; }
				break;
		case VK_LEFT:
			--pos.x;
			if (!m->accessible(getPos()) && !m->ism2(pos.x, pos.y)) { ++pos.x; }
				break;
		case VK_RIGHT:
			++pos.x;
			if (!m->accessible(getPos()) && !m->ism2(pos.x, pos.y)) { --pos.x; }
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

IMAGE* Player::getImg1()
{
	return &loserImg;
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

void Player::beBlown(Map* m)//blown 特效/升级/door
{

	int s=m->searchM(pos.x,pos.y);
	if (s == 666) {
		this->level += 1;
		m->setM(pos.x,pos.y, 0);

	}
	else if (s == -1) {
		this->lives -= 1;
		//this->status = -3;
		pos.x = 0, pos.y = 0;
	}
	else if (s == -2) {
		this->lives -= 1;
		//this->status = -3;
		pos.x = 0, pos.y = 0;
	}
	else if (s == 10) {

	}
}

bool Player::fail()
{
	return lives<=0;
}

void Player::loserdraw(Map* m)
{
	putimagePNG(m->FormTransx(6), m->FormTransy(3), &loserImg);
	FlushBatchDraw();
	Sleep(3000);
}
