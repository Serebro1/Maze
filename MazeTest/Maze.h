#pragma once
#include "Cell.h"
#include "Coin.h"
#include "Wall.h"
#include "Mobs.h"
#include "Landscape.h"
#include "Exit.h"
#include "HeroCell.h"
#define LAB_W 5 // лабиринт 10x10
#define LAB_H 5
class Maze {
	int height, width;
	Cell*** maze;
	void createSample();
	void createStart(int* start);
public:
	Maze(int _h = LAB_H, int _w = LAB_W);
	Maze(const Maze& m);
	~Maze();
	void generation();
	void createEnviroment();
	int getHeight() { return height; };
	int getWidth() { return width; };
	Cell*& getCell(int x, int y) { return maze[x][y]; };
	Maze& operator=(const Maze& map);
	friend ostream& operator <<(ostream& out, Maze& m);
	friend istream& operator >>(istream& in, Maze& m);
};
