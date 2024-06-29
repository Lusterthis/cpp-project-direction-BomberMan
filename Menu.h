#pragma once
#include"Setting.h"

#include"pch.h"
class Menu
{
private:
	int state;
	Setting* set;
	IMAGE MenuImg;
	IMAGE GameStartImg;
	const int L = 1620,H=790;
	int length;
	int height;
	int frame=0;
public:
	Menu(Setting* set) :length(L),height(H){
		this->set = set;
		loadimage(&MenuImg, L"rsc/menu/menu.jpg", set->retcl(), set->retch(), true);
		loadimage(&GameStartImg, L"rsc/menu/startGame.jpg",592,125,true);
	}
	void display();
	IMAGE* retMenu();
	IMAGE* retS();
};

