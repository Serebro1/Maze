#pragma once
#include "Cell.h"
class Coin : public Cell
{
public:
	Coin() { setColor(BrightYellow); };
	Cell* operator+(Hero& hero);
	Cell* operator-(Hero& hero);
	Cell* copy() {
		return new Coin(*this);
	}
	void visit(ostream& out)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (getBackColor() << 4) | getTextColor());
		out << '.';
	}
	char getValue() { return '.'; }
	bool haveHero() { return false; }
};