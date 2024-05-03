#pragma once
#include "GameNet.h"
#include "IObsNet.h"
ShowHeroStatsNet::ShowHeroStatsNet(GameNet^ gm, Panel^ panelStats)
{
	String^ stats;
	stats += "Hp: " + gm->getHero().getHP().ToString() + "\n";
	stats += "Coins: " + gm->getHero().getCoins().ToString() + "\n";
	stats += "Killed Mobs: " + gm->getHero().getKillMobs().ToString() + "\n";
	stats += "Steps: " + gm->getHero().getSteps().ToString();
	lbStats = gcnew Label();
	lbStats->Dock = DockStyle::Fill;
	lbStats->Text = stats;
	lbStats->TextAlign = ContentAlignment::TopLeft;
	lbStats->Font = gcnew Font("Arial", 13);
	panelStats->Controls->Add(lbStats);
}
void ShowHeroStatsNet::event_m(GameNet^ gm)
{
	String^ stats;
	stats += "Hp: " + gm->getHero().getHP().ToString() + "\n";
	stats += "Coins: " + gm->getHero().getCoins().ToString() + "\n";
	stats += "Killed Mobs: " + gm->getHero().getKillMobs().ToString() + "\n";
	stats += "Steps: " + gm->getHero().getSteps().ToString();
	/*lbStats = gcnew Label();
	lbStats->Dock = DockStyle::Fill;*/
	lbStats->Text = stats;
	/*lbStats->TextAlign = ContentAlignment::TopLeft;
	lbStats->Font = gcnew Font("Arial", 13);*/
}
ShowHeroView::ShowHeroView(GameNet^ gm, Panel^ panelHero)
{
	ostringstream maze;
	String^ result;
	int rad = gm->getHero().getRad();
	int x = gm->getHero().getX(), y = gm->getHero().getY();
	int height = gm->getMap().getHeight();
	int width = gm->getMap().getWidth();
	for (int i = x - rad; i <= x + rad; i++)
	{
		for (int j = y - rad; j <= y + rad; j++)
		{
			if ((i < 0) || (j < 0) || (i >= height) || (j >= width)) { maze << "/"; }
			gm->getMap().getCell(i, j)->visit(maze);
		}
		maze << "\n";
	}
	lbHero = gcnew Label();
	lbHero->Dock = DockStyle::Fill;
	result = gcnew String(maze.str().c_str());
	lbHero->Text = result;
	lbHero->Font = gcnew Font("Courier new", 16);
	lbHero->TextAlign = ContentAlignment::MiddleCenter;
	panelHero->Controls->Add(lbHero);
}
void ShowHeroView::event_m(GameNet^ gm)
{
	ostringstream maze;
	String^ result;
	int rad = gm->getHero().getRad();
	int x = gm->getHero().getX(), y = gm->getHero().getY();
	int height = gm->getMap().getHeight();
	int width = gm->getMap().getWidth();
	for (int i = x - rad; i <= x + rad; i++)
	{
		for (int j = y - rad; j <= y + rad; j++)
		{
			if ((i < 0) || (j < 0) || (i >= height) || (j >= width)) { maze << "/"; }
			else gm->getMap().getCell(i, j)->visit(maze);
		}
		maze << "\n";
	}
	/*lbHero = gcnew Label();
	lbHero->Dock = DockStyle::Fill;*/
	result = gcnew String(maze.str().c_str());
	lbHero->Text = result;
	/*lbHero->Font = gcnew Font("Courier new", 16);
	lbHero->TextAlign = ContentAlignment::MiddleCenter;*/
}
ShowMazeView::ShowMazeView(GameNet^ gm, Panel^ panelMaze)
{
	ostringstream maze;
	String^ result;
	int height = gm->getMap().getHeight();
	int width = gm->getMap().getWidth();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			gm->getMap().getCell(i, j)->visit(maze);
		}
		maze << "\n";
	}
	lbMaze = gcnew Label();
	lbMaze->Dock = DockStyle::Fill;
	result = gcnew String(maze.str().c_str());
	lbMaze->Text = result;
	lbMaze->Font = gcnew Font("Courier new", 14);
	lbMaze->TextAlign = ContentAlignment::MiddleCenter;
	panelMaze->Controls->Add(lbMaze);
}
void ShowMazeView::event_m(GameNet^ gm)
{
	ostringstream maze;
	String^ result;
	int height = gm->getMap().getHeight();
	int width = gm->getMap().getWidth();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			gm->getMap().getCell(i, j)->visit(maze);
		}
		maze << "\n";
	}
	/*lbMaze = gcnew Label();
	lbMaze->Dock = DockStyle::Fill;*/
	result = gcnew String(maze.str().c_str());
	lbMaze->Text = result;
	/*lbMaze->Font = gcnew Font("Courier new", 14);
	lbMaze->TextAlign = ContentAlignment::MiddleCenter;
	*/
}

// œ–Œœ»—¿“‹ Œ—“¿À‹Õ€’ Õ¿¡Àﬁƒ¿“≈À≈… » –¿«Œ¡–¿“‹—ﬂ — »’ »—œŒÀ‹«Œ¬¿Õ»≈Ã