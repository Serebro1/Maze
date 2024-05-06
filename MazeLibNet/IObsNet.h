#pragma once
#include "GameNet.h"
public ref class ShowHeroStatsNet : IObserverNet
{
	Label^ lbStats;
public:
	ShowHeroStatsNet(GameNet^ gm, Panel^ panelStats);
	void event_m(GameNet^ gm) override;
};

public ref class ShowHeroView : IObserverNet
{
	Panel^ PHero;
public:
	ShowHeroView(Panel^ pHero) { PHero = pHero; };
	void event_m(GameNet^ gm) override { gm->paintPlayer(PHero, cout); }
};
//
public ref class ShowMazeView : IObserverNet
{
	Panel^ PMaze;
public:
	ShowMazeView(Panel^ pMaze) { PMaze = pMaze; };
	void event_m(GameNet^ gm) override { gm->paintMaze(PMaze, cout); }
};
