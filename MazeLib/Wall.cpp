#include "Wall.h"
Cell* Wall::operator+(Hero& hero)
{
	hero.Damage();
	throw WallEx("Oof!");
}
Cell* Wall::operator-(Hero& hero)
{
	return this;
}
