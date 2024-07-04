#include "Setting.h"
#include"pch.h"
void Setting::display()
{
	int p = 1;
	ExMessage msg;
	while (p)
	{

		loadimage(0, L"rsc/menu/menu.jpg");

		bool b = peekmessage(&msg);
		if (b && msg.lbutton//get the information of mouse, keyboard
			&& msg.x > (length * 0.25)//the location of "start" button,exclude height
			&& msg.x < (length * 0.39))
		{
			//putimage0PNG(length * 0.25, height * 0.526, &GameStartImg);//点击特效 
			//Sleep(100);//可能用来测试
			//m = 0;//jump out of menu
		}
		if (b && msg.message == WM_KEYDOWN//get the information of mouse, keyboard
			&& msg.vkcode == VK_RETURN)
		{

			switch (1) {
			case -1:
				break;
			case 0:
				//choice = 3;
				break;
			case 1:

				//putimage0PNG(length * 0.25, height * 0.526, &GameStartImg);

				//进入游戏循环
				break;
			case 2:
				//putimage0PNG(length * 0.25, height * 0.676, &SetImg);

				///////////////////////////////////////////跳转至set
				break;
			case 3:
				//putimage0PNG(length * 0.25, height * 0.830, &ShopImg);
				break;
			case 4:
				
				break;
			}
		}
		if (b && msg.vkcode == VK_DOWN) {
			if (1) {  }
			else {
			
			}
		}
		if (b && msg.vkcode == VK_UP) {
			if (1 == -1) {}
			else {

			}
		}
		switch (1) {
		case -1:
			break;
		case 0:

			break;
		case 1:


			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		}

		FlushBatchDraw();// in case of flash
		Sleep(100);
	}
}


void Setting::setmx(int x)
{
	mx = x;
}

void Setting::setmy(int y)
{
	my = y;
}

void Setting::setl(int l)
{
	length = l;
}

void Setting::seth(int h)
{
	height = h;
}

int Setting::retmx()
{
	return mx;
}

int Setting::retmy()
{
	return my;
}

int Setting::retl()
{
	return length;
}

int Setting::reth()
{
	return height;
}

int Setting::retch()
{
	return cheight;
}

int Setting::retcl()
{
	return clength;
}

void Setting::FactorySetting()
{
	length = L;
	height = H;
	mx = MX;
	my = MY;
	cheight = CSIZE;
	clength = CSIZE;
}
