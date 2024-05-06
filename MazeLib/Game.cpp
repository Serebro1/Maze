#include "Game.h"
#include "Hero.h"
#include <stdlib.h>
void Game::move(ACTION act)
{
	int x = hero.getX();
	int y = hero.getY();

	switch (act) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if ((x < 0) || (y < 0) || (x >= map.getHeight()) || (y >= map.getWidth()))
		return;
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

}
void Game::randomStart()
{
	int x = 0, y = 0;
	while (x % 2 != 1 || y % 2 != 1 || map.getCell(x, y)->getStatus() || map.getCell(x, y)->getValue() == '.')
	{
		x = (int)(((double)rand() / RAND_MAX) * map.getHeight());
		y = (int)(((double)rand() / RAND_MAX) * map.getWidth());
	}
	map.getCell(x, y) = new HeroCell();
	hero.move(x, y);
}
Game::Game() {
	read();
	randomStart();
	map.createEnviroment();
	evnt();
}
Game::Game(int h, int w, int r)
{
	map = Maze(h, w);
	map.generation();
	save();
	hero.setRad(r);
	randomStart();
	evnt();
}

void Game::paintPlayer(ostream& out, int cellSize)
{
	if (p != nullptr) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
		Cell* emptyCell = new EmptyCell();
		int x = hero.getX(), y = hero.getY(), rad = hero.getRad(), height = map.getHeight(), width = map.getWidth();
		//cout << "Hp: " << hero.getHP() << endl << "Coins: " << hero.getCoins() << endl << "Killed mobs: " << hero.getKillMobs() << endl << "Steps " << hero.getSteps() << endl;
		int startX = hero.getX() - rad;
		int startY = hero.getY() - rad;
		for (int j = startY; j <= y + rad; j++)
		{
			for (int i = startX; i <= x + rad; i++)
			{
				if ((i < 0) || (j < 0) || (i >= height) || (j >= width)) { p->paint(out, emptyCell, i - startX, j - startY); }
				else p->paint(out, map.getCell(i, j), i - startX, j - startY);
			}
			out << endl;
		}
		out << endl;
		delete emptyCell;
	}
}
void Game::paintMaze(ostream& out, int cellSize)
{
	if (p != nullptr)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				p->paint(out, map.getCell(i, j), i, j);
			}
			cout << endl;
		}
		cout << endl;
	}
}
void Game::save()
{
	ofstream file("out.txt");
	file << (map.getHeight() / 2) << " " << (map.getWidth() / 2) << endl;
	file << map;
}
void Game::read()
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
