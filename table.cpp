#include "cell.h"
#include "table.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 
using namespace std;

Table::Table(int sizeX, int sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	srand(time(NULL));
	int lengthAllCoords = _sizeY * _sizeX;
	vector<int>coords(lengthAllCoords,0);
	for (int l = 0; l < lengthAllCoords; l++)
	{
		coords[l] = l;
	}
	_Cells.resize(_sizeY);
	for (int j = 0; j < _sizeY; j++)
	{
		_Cells[j].resize(_sizeX);
	}
	for (int k = 0; k < 2; k++) {
		int randomNumber = rand() % (_sizeX * _sizeY);
		//cout << randomNumber << endl;
		int index = coords[randomNumber];
		for (int j = randomNumber; j < lengthAllCoords - 1; ++j)
		{
			coords[j] = coords[j + 1];
		}

		lengthAllCoords--;

		int xcoord = index / _sizeX;
		int ycoord = index % _sizeY;
		_Cells[xcoord][ycoord].genereNew();
	}
}

Table::Table() : Table( 4, 4 )
{
}


void Table::ShowGrid()
{
	system("CLS");
	cout << endl;
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			cout << _Cells[j][i].getValue();
			if (i != _sizeX - 1)
			{
				cout << " | ";
			}
		}
		cout << endl;
	}
}

void Table::setCell(int x, int y, Cell cell)
{
	_Cells[y][x] = cell;
}

void Table::setCells(vector<vector<Cell>> cells)
{
	_Cells = cells;
}

Cell Table::getCell(int x, int y)
{
	return _Cells[y][x];
}

void Table::RotateGrid(int repeat)
{
	Table actual = Table(_sizeX, _sizeY);
	actual.setCells(_Cells);
	for (int k = 0; k < repeat; k++)
	{
		Table otherTable = Table(actual._sizeY, actual._sizeX);
		for (int j = 0; j < actual._sizeY; j++)
		{
			for (int i = 0; i < actual._sizeX; i++)
			{
				otherTable.setCell(j, actual._sizeY -1 -i, actual.getCell(i, j));
			}
		}
		actual = otherTable;
	}
	_sizeX = actual._sizeX;
	_sizeY = actual._sizeY;
	_Cells = actual._Cells;
}

void Table::gripToLeft()
{
	for (int j = 0; j < _sizeY; j++)
	{
		int offset = 0;
		for (int i = 0; i < _sizeX; i++)
		{
			if (getCell(i, j).getValue() == 0)
			{
				offset++;
			}
			else if (offset != 0)
			{
				setCell(i - offset, j, getCell(i, j));
				_Cells[j][i].reset();
			}
		}
	}
}
void Table::fusionToLeft()
{
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 1; i < _sizeX ; i++)
		{
			if (_Cells[j][i - 1].getValue() == _Cells[j][i].getValue())
			{
				_Cells[j][i - 1].doubl();
				_Cells[j][i].reset();
			}
		}
	}
}

void Table::actionLeft()
{
	gripToLeft();
	fusionToLeft();
	gripToLeft();
}
void Table::actionRight()
{
	RotateGrid(2);
	gripToLeft();
	fusionToLeft();
	gripToLeft();
	RotateGrid(2);
}
void Table::actionUp()
{
	RotateGrid(1);
	gripToLeft();
	fusionToLeft();
	gripToLeft();
	RotateGrid(3);
}
void Table::actionDown()
{
	RotateGrid(3);
	gripToLeft();
	fusionToLeft();
	gripToLeft();
	RotateGrid(1);
}