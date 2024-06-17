#include "Player.h"

Player::Player(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void Player::action(MSG& msg)
{

	switch (msg.message) {
	case VK_UP:
		--pos.y;
		break;
	case VK_DOWN:
		++pos.y;//这个加减容易搞错
		break;
	case VK_LEFT:
		--pos.x;
		break;
	case VK_RIGHT:
		++pos.x;
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
