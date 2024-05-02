#include "Game.h"
#include "Hero.h"
#include <stdlib.h>
void Controller::start()
{
	try {
		char val = _getch();
		while (val != 27) {
			val = _getch();
			if (val == 224)
				val = _getch();
			switch (val)
			{
			case 80:
				game->move(DOWN);
				break;
			case 72:
				game->move(UP);
				break;
			case 75:
				game->move(LEFT);
				break;
			case 77:
				game->move(RIGHT);
				break;
			case 27:
				exit(0);
			}
		}
	}
	catch (const HpEx& gameOver)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BrightRed);
		cout << gameOver.what();
		char Symb = _getch();
		exit(0);
	}
}
void Games::move(ACTION act)
{
	int x = hero.getX();
	int y = hero.getY();

	switch (act) {
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	}
	if ((x < 0) || (y < 0) || (x >= map.getHeight()) || (y >= map.getWidth()))
		return;
	try {
		Cell* heroCell = map.getCell(hero.getX(), hero.getY());
		Cell* mapCell = map.getCell(x, y);
		map.getCell(x, y) = (*map.getCell(x, y)) + hero;
		delete mapCell;
		map.getCell(hero.getX(), hero.getY()) = *heroCell - hero;
		delete heroCell;
		hero.move(x, y);
		hero.PlusSteps();
		//output
		evnt();
		cout << "\33[2K\r";
	}
	catch (const ExitEx& err)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BrightRed);
		cout << "\33[2K\r" << err.what();
	}
	catch (const WallEx& err)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BrightRed);
		cout << "\33[2K\r" << err.what();
		evnt();
	}
}
void Games::randomStart()
{
	int x = 0, y = 0;
	while (x % 2 != 1 || y % 2 != 1 || map.getCell(x, y)->getStatus())
	{
		x = (int)(((double)rand() / RAND_MAX) * map.getHeight());
		y = (int)(((double)rand() / RAND_MAX) * map.getWidth());
	}
	map.getCell(x, y) = new HeroCell();
	hero.move(x, y);
}
Games::Games() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

	cout << "Do you want to load maze from file 'in.txt'? (Y/N)\n";
	unsigned int flag = _getch();
	if (flag == 78) {
		system("cls");
		cout << "Please, enter height and width for maze:\n";
		int height, width;
		cin >> height >> width;
		map = Maze(height, width);
		map.generation();
		save();
	}
	else if (flag == 89) {
		read();
		map.createEnviroment();
	}
	else map.generation();
	randomStart();
	system("cls");
	evnt();
}

//void Game::printPlayer()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
//	int x = hero.getX(), y = hero.getY(), rad = hero.getRad(), height = map.getHeight(), width = map.getWidth();
//	cout << "Hp: " << hero.getHP() << endl << "Coins: " << hero.getCoins() << endl << "Killed mobs: " << hero.getKillMobs() << endl << "Steps " << hero.getSteps() << endl;
//	for (int i = x - rad; i <= x + rad; i++)
//	{
//		for (int j = y - rad; j <= y + rad; j++)
//		{
//			if ((i < 0) || (j < 0) || (i >= height) || (j >= width)) { cout << "/"; }
//			else map.getCell(i, j)->visit(cout);
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
void Games::save()
{
	ofstream file("out.txt");
	file << (map.getHeight() / 2) << " " << (map.getWidth() / 2) << endl;
	file << map;
}
void Games::read()
{
	ifstream file("in.txt");
	int height;
	int width;
	file >> height >> width;
	file.ignore();
	map = Maze(height, width);
	file >> map;
}

//ostream& operator<<(ostream& out, Game& g)
//{
//	g.printPlayer();
//	out << g.map;
//	return out;
//}
