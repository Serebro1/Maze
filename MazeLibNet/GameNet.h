#pragma once
#include "Game.h"
#include "ExceptionNet.h"
#include <vcclr.h>
#include <vector>
#include <sstream>
using namespace System;
using namespace System::Drawing;
//using namespace System::Runtime::InteropServices; // for GCHandle
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::ComponentModel;
using namespace System::Collections::Generic;
using namespace std;

ref class GameNet;

public ref class IObserverNet {
public:
	virtual void event_m(GameNet^ gm) = 0;
};

class Omodel;

public ref class GameNet
{
	Game* g;
	System::Collections::ArrayList^ allObs;
	void addObsC();
public:
	GameNet();
	GameNet(int h, int w, int rad);
	~GameNet();
	void move(ACTION key)
	{
		try {
			g->move(key);
		}
		catch (HpEx e)
		{
			throw gcnew ExZeroHpNet();
		}
		catch (WinEx e)
		{
			throw gcnew ExWinNet();
		}
		catch (WallEx e)
		{
			throw gcnew ExWallHitNet();
		}
		catch (ExitEx e)
		{
			throw gcnew ExExitNet();
		}
	}
	void update() {
		for each (IObserverNet ^ observer in allObs)
			observer->event_m(this);
	}
	void addObserver(IObserverNet^ e)
	{
		allObs->Add(e);

	}
	Maze getMap() { return g->getMap(); }
	Hero getHero() { return g->getHero(); }
};
class Omodel : public IObserverC
{
	gcroot<GameNet^> gm;

public:
	Omodel(GameNet^ _gm) :gm(_gm) {}

	void evnt(Game& g) {
		(gm)->update();
	}
};