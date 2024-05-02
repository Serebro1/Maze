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
	Label^ lbHero;
public:
	ShowHeroView(GameNet^ gm, Panel^ panelStats);
	void event_m(GameNet^ gm) override;
};

public ref class ShowMazeView : IObserverNet
{
	Label^ lbMaze;
public:
	ShowMazeView(GameNet^ gm, Panel^ panelStats);
	void event_m(GameNet^ gm) override;
};
