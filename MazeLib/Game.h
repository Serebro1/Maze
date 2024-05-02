#pragma once
#include "Maze.h"
#include <windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
enum ACTION//множество - перечисление define переменных
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Game;
class IObserverC
{
public:
	virtual void evnt(Game& game) = 0;
};

class Game {
	Maze map;
	Hero hero;
	vector<IObserverC*> allO; // может лучше List? 
	void evnt() { // оповещение всех наблюдателей
		for (IObserverC* o : allO) o->evnt(*this);
	}
public:
	Game(); //конструктор по умолчанию
	Game(int h, int w, int r);
	void move(ACTION act);
	void printMap() { evnt(); };
	//void printPlayer();
	void save();
	void read();
	void randomStart();
	Hero& getHero() { return hero; }
	Maze& getMap() { return map; }
	void addObserver(IObserverC* o) {
		allO.push_back(o);
	}
	//friend ostream& operator <<(ostream& out, Game& g);
};

class Controller {
	Game* game;

public:
	Controller(Game* _game) :game(_game) {}
	void start();
};

//class ShowHpHero : public IObserverC
//{
//	ostream& out;
//public:
//	ShowHpHero(ostream& _out) : out(_out) {}
//	virtual void evnt(Game& game) {
//		out << "\33[2K\r" << "HP: " << game.getHero().getHP() << endl;
//	}
//};
//class ShowCoinsHero : public IObserverC
//{
//	ostream& out;
//public:
//	ShowCoinsHero(ostream& _out) : out(_out) {}
//	virtual void evnt(Game& game) {
//		out << "\33[2K\r" << "Coins: " << game.getHero().getCoins() << endl;
//	}
//};
//class ShowKillMobsHero : public IObserverC
//{
//	ostream& out;
//public:
//	ShowKillMobsHero(ostream& _out) : out(_out) {}
//	virtual void evnt(Game& game) {
//		out << "\33[2K\r" << "Killed Mobs: " << game.getHero().getKillMobs() << endl;
//	}
//};
//class ShowCntStep : public IObserverC
//{
//	ostream& out;
//public:
//	ShowCntStep(ostream& _out) : out(_out) {}
//	virtual void evnt(Game& game) {
//		out << "\33[2K\r" << "Steps " << game.getHero().getSteps() << endl;
//	}
//};
//class ShowHero : public IObserverC
//{
//	ostream& out;
//public:
//	ShowHero(ostream& _out) : out(_out) {}
//	virtual void evnt(Game& game) {
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
//		int x = game.getHero().getX(), y = game.getHero().getY(), rad = game.getHero().getRad();
//		int height = game.getMap().getHeight(), width = game.getMap().getWidth();
//		for (int i = x - rad; i <= x + rad; i++)
//		{
//			for (int j = y - rad; j <= y + rad; j++)
//			{
//				if ((i < 0) || (j < 0) || (i >= height) || (j >= width)) { out << "/"; }
//				else game.getMap().getCell(i, j)->visit(out);
//			}
//			out << endl;
//		}
//		out << endl;
//	}
//};
//class ShowMaze :public IObserverC
//{
//	ostream& out;
//public:
//	ShowMaze(ostream& _out) : out(_out) {}
//	virtual void evnt(Game& game) {
//		out << game.getMap();
//	}
//};
