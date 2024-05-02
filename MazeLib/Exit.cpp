#include "Exit.h"
#include "HeroCell.h"
Cell* Exit::operator+(Hero& hero)
{
	if (this->allCoins > hero.getCoins()) throw ExitEx("Collect all coins to open the exit.");
	// придумать другой сценарий.
	throw WinEx("You Win!!!");
}

Cell* Exit::operator-(Hero& hero)
{
	return this;
}