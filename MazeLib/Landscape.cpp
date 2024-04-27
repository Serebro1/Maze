#include "HeroCell.h"
#include "Landscape.h"
Cell* EmptyCell::operator+(Hero& hero) {
	return new HeroCell();
}
Cell* EmptyCell::operator-(Hero& hero)
{
	return this;
}