#pragma once
#include "Cell.h"
class EmptyCell : public Cell
{
public:
	EmptyCell() { setColor(); };
	Cell* operator+(Hero& hero);
	Cell* operator-(Hero& hero);
	EmptyCell* copy() {
		return new EmptyCell();
	}
	void visit(ostream& out)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (getBackColor() << 4) | getTextColor());
		out << ' ';
	}
	char getValue() { return ' '; }
	bool haveHero() { return false; }
};