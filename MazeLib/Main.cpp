#include "Game.h"
using namespace std;
int main() {
	srand(time(NULL));
	Game g;
	Controller c(&g);
	ShowHpHero viewHp(cout); g.addObserver(&viewHp);
	ShowCoinsHero viewCoins(cout); g.addObserver(&viewCoins);
	ShowKillMobsHero viewKD(cout); g.addObserver(&viewKD);
	ShowCntStep viewStep(cout); g.addObserver(&viewStep);
	ShowHero viewHero(cout); g.addObserver(&viewHero);
	ShowMaze viewMaze(cout); g.addObserver(&viewMaze);
	unsigned int val = 0;
	g.printMap();
	c.start();
	return 0;
}
