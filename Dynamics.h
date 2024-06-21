#pragma once
#include<Windows.h>
#include"Map.h"
class Dynamics//the possible things on the map;

{
private:
protected:
	string name;
	int speed0;
public:
	void shake();
	void putimagePNG(int x, int y, IMAGE* picture);
	virtual void action(ExMessage& msg,Map *m) = 0;
    //virtual bool destroy(Map *m) = 0;
};

