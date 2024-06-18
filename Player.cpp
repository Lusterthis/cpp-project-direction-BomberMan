#include "Player.h"

Player::Player(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

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
		case VK_MENU://alt key

			m->layBomb(pos);
			break;
		}
		
}

bool Player::destroy(Map* m)
{
	vector<vector<int>> mymap = m->getMap();
	if (mymap[pos.x][pos.y] < 0)
	{

		return 1;  
    }
}

Pos Player::getPos()
{
	return pos;
}

int Player::getX()
{
	return pos.x;
}

int Player::getY()
{
	return pos.y;
}
