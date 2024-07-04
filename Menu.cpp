#include "Menu.h"
//#include "Dynamics.h"
//#include"Map.h"
void putimage0PNG(int x, int y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{
	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
void Menu::display()
{
	mciSendString(L"play rsc/bgm/menu.mp3", 0, 0, 0);

	initgraph(length, height, EX_SHOWCONSOLE);
	BeginBatchDraw();
	ExMessage msg;
	bool m = 1;

	while (m) {
		loadimage(0, L"rsc/menu/menu.jpg");
		
		bool b = peekmessage(&msg);
		if (b &&msg.lbutton//get the information of mouse, keyboard
			&& msg.x > (length *0.25)//the location of "start" button,exclude height
			&& msg.x < (length *0.39)) 
		{


			putimage0PNG(length*0.25,height*0.526,&GameStartImg);//点击特效 
			//Sleep(100);//可能用来测试
			m=0;//jump out of menu
		}
		if (b && msg.message==WM_KEYDOWN//get the information of mouse, keyboard
			&& msg.vkcode==VK_RETURN)
		{
			
				switch (choice) {
				case -1:
					break;
				case 0:
					choice = 3;
					break;
				case 1:

					putimage0PNG(length * 0.25, height * 0.526, &GameStartImg);
					m = 0;
					//进入游戏循环
					break;
				case 2:
					putimage0PNG(length * 0.25, height * 0.676, &SetImg);
					//set->display();
					///////////////////////////////////////////跳转至set
					break;
				case 3:
					putimage0PNG(length * 0.25, height * 0.830, &ShopImg);
					break;
				case 4:
					choice = 1;
					break;
				}
		}
		if (b && msg.vkcode == VK_DOWN) {
			if (choice == -1) { choice= 1; }
			else {
				choice += 1;
			}
		}
		if (b && msg.vkcode == VK_UP) {
			if (choice == -1) { choice = 1; }
			else {
				choice -= 1;
			}
		}
		switch (choice) {
		case -1:
			break;
		case 0:
			choice = 3;
			break;
		case 1:

			putimage0PNG(length * 0.25, height * 0.526, &GameStartImg);
			break;
		case 2:
			putimage0PNG(length * 0.25, height * 0.676, &SetImg);
			break;
		case 3:
			putimage0PNG(length * 0.25, height * 0.830, &ShopImg);
			break;
		case 4:
			choice = 1;
			break;
		}
		
		FlushBatchDraw();// in case of flash
		Sleep(16);
	}
	
	mciSendString(L"close rsc/bgm/menu.mp3", 0, 0, 0);
}

IMAGE* Menu::retMenu()
{
	return &MenuImg;
}

IMAGE* Menu::retS()
{
	return &GameStartImg;
}
