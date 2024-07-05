#include "Map.h"
#include"Enemy1.h"


#include<mmsystem.h>
#include<math.h>
#pragma comment(lib,"winmm.lib")
#include<conio.h>


void putimagePNG(int x, int y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
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




Map::Map(Setting* set)
{
	loadimage(&TacoImg, L"rsc/reanim/taco.png", cellSize, cellSize, true);
	loadimage(&BoxImg, L"rsc/reanim/taco.png", cellSize, cellSize, true);
	loadimage(&DoorImg, L"rsc/reanim/door2.png", cellSize, cellSize, true);
	
	loadimage(&BoxImg, L"rsc/reanim/box.png", cellSize, cellSize, true);
	this->marginX = set->retmx();
	this->marginY = set->retmy();
	this->Rows = set->reth();
	this->Cols = set->retl();
	for (int i = 0; i < Cols; ++i) {
		vector<int>row;
		for (int j = 0; j < Rows; ++j) {
			row.push_back(0);
		}

		this->map.push_back(row);
	}
	map[0][0] = 5;
}

void Map::Init()
{

	initgraph(1400, 600, EX_SHOWCONSOLE);
	BeginBatchDraw();
	
	//mciSendString(L"play rsc/bgm/lawnbgm.mp3", 0, 0, 0);
	
	loadimage(&BarrierImg, L"rsc/reanim/Tallnut_body.png", cellSize, cellSize, true);
	loadimage(&BombImg1, L"rsc/reanim/Cherrybomb1.png", cellSize, cellSize, true);
	//Initial
	for (int i = 0; i < Cols; ++i) {
		for (int j = 0; j < Rows; ++j) {
			map[i][j] = 0;
		}
		//map[0][0] = 5;
		
	}
	//MyClass* myArray = static_cast<MyClass*>(operator new[](n * sizeof(MyClass)));
	//Enemy1* e1 = static_cast<Enemy*>(operator new[](n * sizeof(Enemy1));
	Enemy1* e1 = new Enemy1(this);
}

int Map::getCols()
{
	return Cols;
}

int Map::getRows()
{
	return Rows;
}

int Map::getCellSize()
{
	return cellSize;
}

int Map::getLevel()
{
	return level;
}

vector<vector<int>>& Map::getMap()
{
	return map;
}

void Map::printMap(Pos pos)
{
	//double px = pos.x, py = pos.y;
	loadimage(0, L"rsc/background1.jpg");
	for (int i = 0; i < Cols; ++i)//i->map[i][]
	{
		for (int j = 0; j < Rows; ++j) 
		{
			switch (map[i][j]) {
			case 1:
				putimagePNG(FormTransx(i), FormTransy(j), &BarrierImg);
				break;
			case 2:
			case 667:
			case 11:
				putimagePNG(FormTransx(i), FormTransy(j), &BoxImg);
				break;
			case 10:
				putimagePNG(FormTransx(i), FormTransy(j), &DoorImg);
				break;
			case 666:
				putimagePNG(FormTransx(i), FormTransy(j), &TacoImg);
				//putimagePNG(FormTransx(i), FormTransy(j), &BoxImg);
				break;
			case -1:
				putimagePNG(FormTransx(i), FormTransy(j), &FireImg);
				break;
			case 0:
				break;
			
			
			

			}
		}
	}


	
}

void Map::updateMap()
{
	++level;
}

void Map::setPlayer(int x, int y)
{
	//map[x][y] = 5;
}

void Map::setPlayer(Pos pos)
{

	if(accessible(pos))
	map[pos.x][pos.y] = 5;
}

void Map::leavePlayer(Pos pos)
{
	map[pos.x][pos.y] = 0;
}

double Map::FormTransx(double posn)
{
	 posn = marginX + posn * cellSize - 0.5 * cellSize;
	
	return posn;
}

double Map::FormTransy(double posn)
{
	posn = marginY + posn * cellSize - 0.5 * cellSize;
	return posn;
}

bool Map::accessible(int x,int y)
{
	return x >= 0 && y >= 0 && x < Cols && y < Rows 
		&&( map[x][y] == 0 ||map[x][y] == -1
		||map[x][y]==666||map[x][y]==10);
}

bool Map::accessible(Pos pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < Cols 
		&& pos.y < Rows && (map[pos.x][pos.y] == 0 || map[pos.x][pos.y] == -1
			|| map[pos.x][pos.y] == 666||map[pos.x][pos.y]==10);
}

bool Map::won(Pos pos)
{
	if (map[pos.x][pos.y] == 10)
		return 1;
	else
		return 0;
}

bool Map::is2(Pos pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < Cols && pos.y < Rows && map[pos.x][pos.y] == 2;
}

bool Map::is2(int x, int y)
{
	return x >= 0 && y >= 0 && x < Cols && y < Rows && map[x][y] == 2;
}

bool Map::is1(int x, int y)
{
	return x >= 0 && y >= 0 && x < Cols && y < Rows && map[x][y] == 1;
}

bool Map::ism2(int x, int y)
{
	return x >= 0 && y >= 0 && x < Cols && y < Rows && map[x][y] == -2;
}

bool Map::is10(Pos pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < Cols && pos.y < Rows && map[pos.x][pos.y] == 10;
}

bool Map::is11(int x, int y)
{
	if (x >= 0 && y >= 0 && x < Cols && y < Rows) {


		if (map[x][y] == 11)
			return 1;
		else
			return 0;
	}
	return 0;
}

bool Map::is667(int x, int y)
{
	if (x >= 0 && y >= 0 && x < Cols && y < Rows) {
		if (map[x][y] == 667)
			return 1;
		else
			return 0;
	}
	return 0;
}

void Map::layBomb(Pos pos)
{

	map[pos.x][pos.y] = 5;

}

void Map::scene0()
{
	for (int i = 1; i < Cols; i += 2) {
		for (int j = 1; j < Rows; j += 2) {
			map[i][j] = 1;
		}
	}
}

void Map::scenex()
{
	//srand(time(0));
	for (int i = 2; i < Cols; ++i) {
		for (int j = 2; j < Rows; ++j) {
			int r = rand() % 10;
			if(r<4)
			map[i][j] = 1;
		}
	}
	
}

void Map::box()
{
	for (int i = 2; i < Cols; ++i) {
		for (int j = 2; j < Rows; ++j) {
			int r = rand() % 100;
			if (r < 1&&accessible(i,j))
				map[i][j] = 2;
		}
	}
}

void Map::taco()
{
	int x, y;
	do {
		 x = rand() % Cols;
		 y = rand() % Rows;
	} while (is2(x, y)||is1(x,y));
	map[x][y] = 667;
	//putimagePNG(FormTransx(x), FormTransy(y), &TacoImg);
}

void Map::door()
{
	int x, y;
	do {
		x = rand() % Cols+1;
		y = rand() % Rows+1;
	} while (is2(x, y)||is1(x,y));
	map[x][y] = 11;
	//putimagePNG(FormTransx(x), FormTransy(y), &TacoImg);
}

void Map::BombBlow(int x,int y)
{

	if(bombnum)
	putimagePNG(FormTransx(x), FormTransy(y), &BombImg1);//lay bomb;

}

int Map::searchM(int x, int y)
{
	return map[x][y];
}

void Map::setF(Pos pos, int g)
{
	if(accessible(pos)||is2(pos.x,pos.y)||ism2(pos.x,pos.y))
	map[pos.x][pos.y] = g;
}

void Map::setF(int x, int y, int g)
{
	if(accessible(x,y)||is2(x,y)||ism2(x,y))//in case of overstep
	map[x][y] = g;
}



void Map::setF1(int x, int y, int g)
{
	if ( accessible(x, y) || is2(x, y) || ism2(x, y))//in case of overstep
		if (!(map[x][y] == 666 || map[x][y] == 10))
			map[x][y] = g;
}


void Map::setM(int x, int y, int g)
{
	if(accessible(x,y))
		map[x][y] = g;
}

void Map::setM1(int x, int y, int g)
{
	if (x >= 0 && y >= 0 && x < Cols && y < Rows
		|| map[x][y] == 667 || map[x][y] == 11)
		map[x][y] = g;
}



