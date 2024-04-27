#include "Game.h"
Cell::Cell(const Cell& c)
{
	visited = c.visited;
	textColor = c.textColor;
	backColor = c.backColor;
}
istream& operator >>(istream& in, Cell*& c)
{
	char val;
	in >> val;
	switch (val) // ���� � ����� �������, ��� ����� �� ���� ������������� �� �� ��������� ������(*&), � �������� ���� ������(&) + �������� ��������� � ������������ ����
	{
	case '#':
		c = new Wall();
		break;
	case '.':
		c = new Coin();
		break;
	default:
		c = new EmptyCell();
		break;
	}
	return in;
}

Cell& Cell::operator=(const Cell& cell)
{
	if (this == &cell) return *this;
	textColor = cell.textColor;
	backColor = cell.backColor;
	visited = cell.visited;
	return *this;
}
