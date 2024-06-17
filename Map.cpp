#include "Map.h"

#include<mmsystem.h>
#include<math.h>
#pragma comment(lib,"winmm.lib")
#include<conio.h>



void putimagePNG(int x, int y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
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

void Map::Init()
{
	initgraph(1400, 600, EW_SHOWCONSOLE);
	loadimage(0, L"rsc/background1.jpg");
	mciSendString(L"play rsc/bgm/lawnbgm.mp3", 0, 0, 0);
	loadimage(&PlayerImg, L"rsc/reanim/Taco.png", cellSize, cellSize, true);
	loadimage(&BarrierImg, L"rsc/reanim/Tallnut_body.png", cellSize, cellSize, true);
	//Initial
	for (int i = 0; i < Cols; ++i) {
		for (int j = 0; j < Rows; ++j) {
			map[i][j] = 0;
		}
		map[0][0] = 5;
		
	}
}

vector<vector<int>>& Map::getMap()
{
	return map;
}

void Map::printMap()
{
	
	for (int i = 0; i < Cols; ++i)//i->map[i][]
	{
		for (int j = 0; j < Rows; ++j) 
		{
			switch (map[i][j]) {
			case -1:
				putimagePNG(FormTrans(i), FormTrans(j), &FireImg);
				break;
			case 0:
				break;
			case 1:
				putimagePNG(FormTrans(i), FormTrans(j), &BarrierImg);
				break;
			case 5:
				putimagePNG(FormTrans(i), FormTrans(j), &PlayerImg);
				break;
			case 2:
				putimagePNG(FormTrans(i), FormTrans(j), &BarrierImg);
				break;

			}
		}
	}
}

void Map::setPlayer(int x, int y)
{
	map[x][y] = 5;
}

void Map::setPlayer(Pos pos)
{
	map[pos.x][pos.y] = 5;
}

double Map::FormTrans(double posn)
{
	 posn = marginX + posn * cellSize - 0.5 * cellSize;
	
	return posn;
}


