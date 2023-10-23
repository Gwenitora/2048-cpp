#include "cell.h"
#include "table.h"
#include <iostream>
#include <vector>
using namespace std;

class Table
{
	vector<vector<Cell>> _Cells;
	int _sizeX;
	int _sizeY;

	Table(int sizeX, int sizeY)
	{
		_sizeX = sizeX;
		_sizeY = sizeY;

		_Cells.resize(_sizeY);
		for (int j = 0; j < _sizeY; j++)
		{
			_Cells[j].resize(_sizeX);
		}
	}

	int operator<<(int i)
	{
		for (int j = 0; j < _sizeY; j++)
		{
			for (int i = 0; i < _sizeX; i++)
			{
				cout << _Cells[j][i].getValue();
				cout << ", ";
			}
			cout << endl;
		}
	}
};