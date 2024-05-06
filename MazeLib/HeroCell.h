#pragma once
#include "Cell.h"
class HeroCell : public Cell
{
public:
	HeroCell() { setColor(Cyan); };
	Cell* operator+(Hero& hero);
	Cell* operator-(Hero& hero);
	HeroCell* copy() {
		return new HeroCell();
	}
	void visit(ostream& out)
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (getBackColor() << 4) | getTextColor());
		out << '*';
	}
	string getImage() { return "hero"; }
	char getValue() { return '*'; }
	bool haveHero() { return true; }
};