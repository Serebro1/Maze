#include "GameNet.h"
/*
модель котора€ хранит указатели на — модель
метод move

*/
GameNet::GameNet()
{
	srand(time(NULL));
	g = new Game();
	allObs = gcnew List<IObserverNet^>(3);
	addObsC();
}
GameNet::GameNet(int _h, int _w, int _rad)
{
	srand(time(NULL));
	g = new Game(_h, _w, _rad);
	allObs = gcnew List<IObserverNet^>(3);
	addObsC();
}
GameNet::~GameNet()
{
	delete g;
	for each (IObserverNet ^ observer in allObs)
		delete observer;
	delete allObs;
}
void GameNet::addObsC()
{
	Omodel* tmp = new Omodel(this);
	g->addObserver(tmp);
}