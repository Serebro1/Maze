#pragma once
#include "Cell.h"
class Wall : public Cell
{
public:
	Wall() { setColor(Gray); };
	Cell* operator+(Hero& hero);
	Cell* operator-(Hero& hero);
	Cell* copy() {
		return new Wall(*this);
	}
	void visit(ostream& out)
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (getBackColor() << 4) | getTextColor());
		out << '#';
	}
	string getImage() { return "wall"; }
	char getValue() { return '#'; }
	bool haveHero() { return false; }
};
