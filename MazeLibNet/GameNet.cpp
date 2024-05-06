#include "GameNet.h"
void GrPainter::paint(ostream& out, Cell*& c, int x, int y)
{
	string imageName = c->getImage() + ".ico";
	auto search = images.find(imageName);
	if (search == images.end())
	{
		String^ tmp = gcnew String((c->getImage() + ".ico").c_str());
		gcroot<Icon^> newImage = gcnew Icon(tmp);

		images[imageName] = newImage;
	}
	rect = Drawing::Rectangle(x * CellSize, y * CellSize, CellSize, CellSize);
	gr->DrawIcon(images[imageName], rect);
		
}
void GameNet::paintPlayer(Panel^ p, ostream& out)
{
	if (painter == nullptr)
	{
		painter = new GrPainter(p->CreateGraphics(), p);
		g->init(painter);
	}
	painter->setGr(p->CreateGraphics(), p);
	g->paintPlayer(cout);
}
void GameNet::paintMaze(Panel^ p, ostream& out)
{
	if (painter == nullptr)
	{
		painter = new GrPainter(p->CreateGraphics(), p);
		g->init(painter);
	}
	painter->setGr(p->CreateGraphics(), p);
	g->paintMaze(cout);
}
GameNet::GameNet()
{
	srand(time(NULL));
	g = new Game();
	allObs = gcnew System::Collections::ArrayList(0);
	addObsC();
	painter = nullptr;
}
GameNet::GameNet(int _h, int _w, int _rad)
{
	srand(time(NULL));
	g = new Game(_h, _w, _rad);
	allObs = gcnew System::Collections::ArrayList(0);
	addObsC();
	painter = nullptr;

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