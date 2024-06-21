#pragma once
#include "Dynamics.h"
#include<vector>
#include<ctime>
#include<random>
class Enemy :
    public Dynamics

{
public:
  
    virtual void action(ExMessage& msg, Map* m)=0;
    
};

