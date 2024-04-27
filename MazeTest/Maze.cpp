#include "Maze.h"
#include <iostream>
#include <stdlib.h>
Maze::Maze(int _h, int _w) : height((_h * 2) + 1), width((_w * 2) + 1) {
	maze = new Cell ** [height];
	for (int i = 0; i < height; i++) {
		maze[i] = new Cell * [width];
		for (int j = 0; j < width; j++) {
			maze[i][j] = new EmptyCell();
		}
	}
}
Maze::Maze(const Maze& m)
{
	height = m.height;
	width = m.width;
	maze = new Cell * *[height];
	for (int i = 0; i < height; i++)
	{
		maze[i] = new Cell * [width];
		for (int j = 0; j < width; j++)
		{
			maze[i][j] = m.maze[i][j]->copy();
		}
	}
}
;
Maze::~Maze()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			delete maze[i][j];
		delete[](maze[i]);
	}
	delete[](maze);
}
Maze& Maze::operator=(const Maze& map)
{
	if (this == &map) { return *this; }
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			delete maze[i][j];
		delete[](maze[i]);
	}
	delete[](maze);
	height = map.height;
	width = map.width;
	maze = new Cell ** [height];
	for (int i = 0; i < height; i++)
	{
		maze[i] = new Cell*[width];
		for (int j = 0; j < width; j++)
		{
			maze[i][j] = map.maze[i][j]->copy();
		}
	}
	return *this;
}

void Maze::createSample()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((i < height - 1 && j < width - 1) && (i % 2 != 0 && j % 2 != 0))
				maze[i][j] = new EmptyCell(); // cell inside maze and on odd coord
			else maze[i][j] = new Wall(); // walls
		}
	}
}
//Random generate start and finish cell
void Maze::createStart(int* start)
{
	//x, y
	int fin[2];//finish
	int temp;
	int ch_direct = rand();// choose x or y main coord
	if (ch_direct % 2 == 0)//0 main
	{
		fin[0] = (temp = rand() % (height - 1)) % 2 == 1 ? temp : temp + 1; // if () then temp else temp + 1
		if (rand() % 2 == 1) {
			fin[1] = width - 1;//right wall
			start[1] = fin[1] - 1;
		}
		else {
			fin[1] = 0; //left wall
			start[1] = fin[1] + 1;
		}
		start[0] = fin[0];
	}
	else// 1 main
	{
		fin[1] = (temp = rand() % (width - 1)) % 2 == 1 ? temp : temp + 1;
		if (rand() % 2 == 1) { // down wall
			fin[0] = height - 1;
			start[0] = fin[0] - 1;
		}
		else {
			fin[0] = 0; // upper wall
			start[0] = fin[0] + 1;
		}
		start[1] = fin[1];
	}
	maze[fin[0]][fin[1]] = new EmptyCell(); // finish

}

void Maze::createEnviroment()
{
	int coins = 0;
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1 ; j++)
		{
			int rng = rand();
			if (maze[i][j]->getValue() == ' ')
			{
				if (rng % 10 == 0) {
					maze[i][j] = new Coin();
					coins++;
				}
				if (rng % 10 == 1) {
					maze[i][j] = new Skelet();
				}
			}
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {
			if ((i == 0 || j == 0 || i == height - 1 || j == width - 1) && maze[i][j]->getValue() == ' ') { maze[i][j] = new Exit(coins); }
		}
	}
}

void Maze::generation()
{
	createSample();
	int start[2];//start cell for generate labyrith
	createStart(start);
	maze[start[0]][start[1]] = new EmptyCell();
	maze[start[0]][start[1]]->setStatus(true);
	int cells = ((height - 1) / 2) * ((width - 1) / 2);
	int** vis_cells = new int* [cells];// store visited cells;
	for (int i = 0; i < cells; i++)
		vis_cells[i] = new int[2];
	cells -= 1; // non visited cells
	vis_cells[cells][0] = start[0]; vis_cells[cells][1] = start[1];
	int count = cells; //
	int current[2] = { vis_cells[cells][0], vis_cells[cells][1] };
	int tmp = 0;
	while (cells > 0)
	{
		tmp++;
		int direct;
		int flag = 1;
		for (int i = 0; i < 16; i++)// check all directions
		{
			direct = rand() % 4;
			if (direct == 0 && current[1] != 1 && !maze[current[0]][current[1] - 2]->getStatus()) // left
			{
				maze[current[0]][current[1] - 2] = new EmptyCell(); // become visited
				maze[current[0]][current[1] - 2]->setStatus(true);
				maze[current[0]][current[1] - 1] = new EmptyCell(); // delete walls
				maze[current[0]][current[1] - 1]->setStatus(true);
				cells--;
				vis_cells[cells][0] = current[0]; vis_cells[cells][1] = current[1] - 2; // remember visited cell
				current[1] -= 2; // 
				flag = 0;
				break;
			}
			if (direct == 1 && current[0] != 1 && !maze[current[0] - 2][current[1]]->getStatus()) // up
			{
				maze[current[0] - 2][current[1]] = new EmptyCell();
				maze[current[0] - 2][current[1]]->setStatus(true);
				maze[current[0] - 1][current[1]] = new EmptyCell();
				maze[current[0] - 1][current[1]]->setStatus(true);
				cells--;
				vis_cells[cells][0] = current[0] - 2; vis_cells[cells][1] = current[1];
				current[0] -= 2;
				flag = 0;
				break;
			}
			if (direct == 2 && current[1] != width - 2 && !maze[current[0]][current[1] + 2]->getStatus()) // right
			{
				maze[current[0]][current[1] + 2] = new EmptyCell();
				maze[current[0]][current[1] + 2]->setStatus(true);
				maze[current[0]][current[1] + 1] = new EmptyCell();
				maze[current[0]][current[1] + 1]->setStatus(true);
				cells--;
				vis_cells[cells][0] = current[0]; vis_cells[cells][1] = current[1] + 2;
				current[1] += 2;
				flag = 0;
				break;
			}
			if (direct == 3 && current[0] != height - 2 && !maze[current[0] + 2][current[1]]->getStatus()) // down
			{
				maze[current[0] + 2][current[1]] = new EmptyCell();
				maze[current[0] + 2][current[1]]->setStatus(true);
				maze[current[0] + 1][current[1]] = new EmptyCell();
				maze[current[0] + 1][current[1]]->setStatus(true);
				cells--;
				vis_cells[cells][0] = current[0] + 2; vis_cells[cells][1] = current[1];
				current[0] += 2;
				flag = 0;
				break;
			}
		}
		if (flag) // found dead end
		{
			current[0] = vis_cells[count][0]; current[1] = vis_cells[count][1]; // this end become visited
			count--;// go back for check another wa1s
			if (count == 0) count = ((height - 1) / 2) * ((width - 1) / 2) - 1;
		}
	}
	createEnviroment();
	for (int i = 0; i < cells; i++)
		delete[]vis_cells[i];
	delete[]vis_cells;
}

istream& operator >>(istream& in, Maze& m)
{

	for (int i = 0; i < m.getHeight(); i++)// 1 вариант считывания лабиринта
	{
		for (int j = 0; j < m.getWidth(); j++)
			in >> noskipws >> m.getCell(i, j);
		in.ignore();
	}
	return in;
}
ostream& operator <<(ostream& out, Maze& m)
{
	for (int i = 0; i < m.getHeight(); i++)
	{
		for (int j = 0; j < m.getWidth(); j++)
			m.getCell(i, j)->visit(out);
		out << endl;
	}
	return out;
}

