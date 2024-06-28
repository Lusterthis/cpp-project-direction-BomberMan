#include "Setting.h"

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
