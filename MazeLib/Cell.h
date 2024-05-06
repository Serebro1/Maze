#pragma once
#include "Hero.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Windows.h"
using namespace std;

enum Colors {
	Black,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White,
	Gray,
	BrightBlue,
	BrightGreen,
	BrightCyan,
	BrightRed,
	BrightMagenta,
	BrightYellow,
	BrightWhite,
};

class Cell {
	//char value;
	//если не пустой, то отображается герой, если пустой, то ячейка просто отображается
	Colors textColor, backColor;
	bool visited = false;
public:
	Cell() = default; //пустая клетка по умолчанию;
	Cell(const Cell& c);

	virtual Cell* copy() = 0;
	virtual char getValue() = 0;
	virtual Cell* operator+(Hero& hero) = 0;
	virtual Cell* operator-(Hero& hero) = 0;
	virtual void visit(ostream& out) = 0;
	virtual bool haveHero() = 0;
	virtual string getImage() = 0;
	bool getStatus() { return visited; }
	void setStatus(bool _visited) { visited = _visited; }

	void setColor(Colors _textColor = Black, Colors _backColor = Black) { textColor = _textColor; backColor = _backColor; }
	Colors getTextColor() { return textColor; }
	Colors getBackColor() { return backColor; }

	Cell& operator=(const Cell& cell);
	friend istream& operator >>(istream& in, Cell*& c);
};