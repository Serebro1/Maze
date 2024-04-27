#include "Exit.h"
#include "HeroCell.h"
Cell* Exit::operator+(Hero& hero)
{
	if (this->allCoins > hero.getCoins()) throw ExitEx("Collect all coins to open the exit.");
	// придумать другой сценарий.
	return new HeroCell();
}

Cell* Exit::operator-(Hero& hero)
{
	return this;
}