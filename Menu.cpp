#include "Menu.h"

void Menu::display()
{
	//mciSendString(L"play rsc/bgm/lawnbgm.mp3", 0, 0, 0);
	mciSendString(L"play rsc/bgm/menu.mp3", 0, 0, 0);


	initgraph(1620, 790, EX_SHOWCONSOLE);
	BeginBatchDraw();
	ExMessage msg;
	bool m = 1;
	while (1&&m) {

		bool b = peekmessage(&msg);
		loadimage(0, L"rsc/menu/menu.jpg");
		FlushBatchDraw();
		
	}
	
	mciSendString(L"close rsc/bgm/menu.mp3", 0, 0, 0);
}

IMAGE* Menu::retMenu()
{
	return &MenuImg;
}
