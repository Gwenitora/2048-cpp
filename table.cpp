#include "cell.h"
#include <iostream>
//using namespace std;

class Table
{
	std::vector<list<Cell>> _Cells;
	int _sizeX;
	int _sizeY;

	Table(int sizeX, int sizeY)
	{
		_sizeX = sizeX;
		_sizeY = sizeY;
	}
};