#pragma once
#include<Windows.h>
#include"Map.h"
class Dynamics//the possible things on the map;

{
private:

public:
	void shake();
	virtual void action(ExMessage& msg,Map *m) = 0;
	virtual bool destroy(Map *m) = 0;
};

