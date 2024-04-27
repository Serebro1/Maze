#pragma once
#include "Cell.h"
class Exit : public Cell
{
	int allCoins;
public:
	Exit(int _allCoins) : allCoins(_allCoins){ setColor(Black, Green);};
	Cell* operator+(Hero& hero);
	Cell* operator-(Hero& hero);
	Cell* copy() {
		return new Exit(*this);
	}
	void visit(ostream& out)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (getBackColor() << 4) | getTextColor());
		out << ' ';
	}
	char getValue() { return ' '; }
	bool haveHero() { return false; }
};