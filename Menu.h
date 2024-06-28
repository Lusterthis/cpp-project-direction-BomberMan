#pragma once
#include"Setting.h"
#include<Windows.h>
#include"graphics.h"
class Menu
{
private:
	Setting* set;
	IMAGE MenuImg;
public:
	Menu(Setting* set) {
		this->set = set;
		loadimage(&MenuImg, L"rsc/menu.jpg", set->retcl(), set->retch(), true);
	}
	void display();
	IMAGE* retMenu();
};

