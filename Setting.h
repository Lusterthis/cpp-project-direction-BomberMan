#pragma once
//#include"pch.h"
class Setting
{
private:
	const int MX = 257, MY = 86, L = 30, H= 15,CSIZE=30;//by default
	int mx;//marginx,marginy
	int my;
	int length;
	int height;
	int clength;
	int cheight;

public:
	Setting() {
		mx = MX, my = MY;
		length = L, height = H;
		clength = CSIZE;
		cheight = CSIZE;
	}
	void display();
	void setmx(int x);
	void setmy(int y);
	void setl(int l);
	void seth(int h);
	int retmx();
	int retmy();
	int retl();
	int reth();
	int retch();
	int retcl();
	void FactorySetting();
};

