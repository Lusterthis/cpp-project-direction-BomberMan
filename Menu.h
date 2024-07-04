#pragma once
#include"Setting.h"

#include"pch.h"
class Menu
{
private:
	int state;
	int choice = -1;
	Setting* set;
	IMAGE MenuImg;
	IMAGE GameStartImg;
	IMAGE SetImg;
	IMAGE ShopImg;
	const int L = 1620,H=790;
	int length;
	int height;
	int frame=0;
public:
	Menu(Setting* set) :length(L),height(H){
		this->set = set;
		loadimage(&MenuImg, L"rsc/menu/menu.jpg", set->retcl(), set->retch(), true);
		loadimage(&GameStartImg, L"rsc/menu/startGame.jpg",592,125,true);
		loadimage(&SetImg, L"rsc/menu/set.jpg", 592, 125, true);
		loadimage(&ShopImg, L"rsc/menu/shop.jpg", 592, 125, true);
	}
	void display();
	IMAGE* retMenu();
	IMAGE* retS();
};

