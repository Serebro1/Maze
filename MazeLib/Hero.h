#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HeroEx.h"
class Hero
{
	int x = 1, y = 1, rad, coins, hp, killMobs, steps;
public:
	Hero(int _rad = 1, int _hp = 10, int _coins = 0) : rad(_rad), coins(_coins), hp(_hp), killMobs(0), steps(0){};
	int getX() { return x; }
	int getY() { return y; }
	int getRad() { return rad; }
	int getCoins() { return coins; }
	int getHP() { return hp; }
	int getKillMobs() { return killMobs; }
	int getSteps() { return steps; }
	void PlusSteps(int val = 1) { steps += val; }
	void KillMobs(int val = 1) { killMobs += val; }
	void PlusCoin(int val = 1) { coins += val; }
	void Damage(int val = 1) { hp -= val; if (hp < 1) throw HpEx("Game Over. Press escape to exit or any key to end."); }
	void move(int _x = 1, int _y = 1) { y = _y; x = _x; }
};