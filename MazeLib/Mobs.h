#pragma once
#include "Cell.h"
class Skelet : public Cell
{
public:
	Skelet() { setColor(Red); };
	Cell* operator+(Hero& hero);
	Cell* operator-(Hero& hero);
	Cell* copy() {
		return new Skelet(*this);
	}
	void visit(ostream& out)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (getBackColor() << 4) | getTextColor());
		out << '@';
	}
	char getValue() { return '@'; }
	bool haveHero() { return false; }
};