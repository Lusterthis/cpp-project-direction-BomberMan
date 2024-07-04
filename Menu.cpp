#include "Menu.h"
//#include "Dynamics.h"
//#include"Map.h"
void putimage0PNG(int x, int y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{
	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
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


			putimage0PNG(length*0.25,height*0.526,&GameStartImg);//�����Ч 
			//Sleep(100);//������������
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
					//������Ϸѭ��
					break;
				case 2:
					putimage0PNG(length * 0.25, height * 0.676, &SetImg);
					//set->display();
					///////////////////////////////////////////��ת��set
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
