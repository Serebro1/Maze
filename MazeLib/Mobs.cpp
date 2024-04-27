#include "Mobs.h"
#include "HeroCell.h"
Cell* Skelet::operator+(Hero& hero)
{
	hero.Damage();
	hero.KillMobs();
	return new HeroCell();
}
Cell* Skelet::operator-(Hero& hero)
{
	return this;
}

