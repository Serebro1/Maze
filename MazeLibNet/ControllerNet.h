#pragma once
#include "GameNet.h"
public ref class ControllerNet
{
	GameNet^ gmNet;
public:
	void step(int val);
	ControllerNet(GameNet^ _gmNet) :gmNet(_gmNet) {}
};