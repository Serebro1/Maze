#include "HeroCell.h"
#include "Landscape.h"
Cell* HeroCell::operator+(Hero& hero)
{
	return new HeroCell();
}
Cell* HeroCell::operator-(Hero& hero)
{
	return new EmptyCell();
}