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
		int is4 = rand() % 10 + 1;
		if(is4<9)
		{
			_Cells[xcoord][ycoord]._value = 2;
		}
		else {
			_Cells[xcoord][ycoord]._value = 4;
		}

	}
}

Table::Table() : Table( 4, 4 )
{
}


void Table::ShowGrid()
{
	system("CLS");
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