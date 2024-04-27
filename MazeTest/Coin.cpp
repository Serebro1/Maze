#include "HeroCell.h"
#include "Coin.h"
Cell* Coin::operator+(Hero& hero)
{
	hero.PlusCoin();
	return new HeroCell();
}

Cell* Coin::operator-(Hero& hero)
{
	return this;
}
