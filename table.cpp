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
	_lengthAllCoords = _sizeY * _sizeX;
	_inGame = 1;
	_played = 0;
	_Cells.resize(_sizeY);
	for (int j = 0; j < _sizeY; j++)
	{
		_Cells[j].resize(_sizeX);
	}
	//_tableCopy = _Cells;
	NextTurn();
}

Table::Table() : Table( 2, 2 )
{
}

void Table::Regen()
{
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			_Cells[j][i].reset();
		}
	}
	NextTurn();
}

void Table::Gen(int number ,vector<int> list) 
{
	int listSize = list.size();
	//vector<int>coords(lengthAllCoords, 0);
	for (int k = 0; k < number; k++) {
		//int randomNumber = rand() % (_sizeX * _sizeY);
		////cout << randomNumber << endl;
		//int index = coords[randomNumber];
		//for (int j = randomNumber; j < lengthAllCoords - 1; ++j)
		//{
		//	coords[j] = coords[j + 1];
		//}

		//lengthAllCoords--;

		//int xcoord = index / _sizeX;
		//int ycoord = index % _sizeY;
		//_Cells[xcoord][ycoord].genereNew();
		int randomNumber = rand() % (listSize);
		int index = list[randomNumber];
		int xcoord = index / _sizeX;
		int ycoord = index % _sizeY;
		_Cells[xcoord][ycoord].genereNew();
		for (int j = randomNumber; j < listSize - 1; j++)
		{
			list[j] = list[j + 1];
		}
		listSize--;
	}
}

vector<int> Table::getEmptyCells(vector<vector<Cell>> table)
{
	vector<int> list;
	for (int i = 0; i < _sizeY;i++) {
		for (int j = 0; j < _sizeX; j++) {
			if (table[i][j].getValue() == 0) {
				list.push_back((i * _sizeY) + j);
			}
		}
	}
	return list;
}

void Table::NextTurn() {
	_played = 0;
	vector<int> EmptyCells = getEmptyCells(_Cells);
	//for (int i = 0; i < EmptyCells.size(); i++)
	//{
	//	cout << EmptyCells[i];
	//}
	if (_lengthAllCoords == EmptyCells.size()) {
		Gen(2, EmptyCells);
	}
	else {
		Gen(1, EmptyCells);
	}
	int isTheGameOver = gameOver();
	if (isTheGameOver) {
		_inGame = 0;
	}
}

int Table::gameOver() {
	vector<int> EmptyCells = getEmptyCells(_Cells);
	if (EmptyCells.size() == 0)
	{
		Table tableCopy = createCopy();
		tableCopy._played = 0;
		tableCopy.fusion();
		tableCopy.RotateGrid(2);
		tableCopy.fusion();
		tableCopy.RotateGrid(2);
		tableCopy.RotateGrid(1);
		tableCopy.fusion();
		tableCopy.RotateGrid(3);
		tableCopy.RotateGrid(3);
		tableCopy.fusion();
		tableCopy.RotateGrid(1);
		if(!tableCopy._played)
		{
			return 1;
		}
	}
	for (int i = 0; i < _sizeY; i++)
	{
		for (int j = 0; j < _sizeX; j++)
		{
			if (_Cells[i][j].getValue() == 2048) {
				return 2;
			}
		}
	}
	return 0;
}

Table Table::createCopy()
{
	Table tableCopy = Table(_sizeX, _sizeY);
	tableCopy.setCells(_Cells);
	return tableCopy;

}

void Table::ShowGrid()
{
	system("CLS");
	int maxSize = log10(4 * pow(2, (_sizeX * _sizeY))) - .5f;
	string preString = " ";
	string verticalSeperation = " | ";
	string horizontalSeperation = " ";
	for (int i = 0; i < (maxSize + 4) * _sizeX + 1; i++)
	{
		horizontalSeperation += "-";
	}
	string horizontalEmptySeperation = verticalSeperation;
	for (int i = 0; i < _sizeX; i++)
	{
		for (int i = 0; i < maxSize +1; i++)
		{
			horizontalEmptySeperation += preString;
		}
		horizontalEmptySeperation += verticalSeperation;
	}
	for (int j = 0; j < _sizeY; j++)
	{
		cout << endl << horizontalSeperation;
		for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
		{
			cout << endl << horizontalEmptySeperation;
		}
		cout << endl << verticalSeperation;
		for (int i = 0; i < _sizeX; i++)
		{
			int len = (maxSize - (_Cells[j][i].getValue() == 0 ? 1 : log10(_Cells[j][i].getValue())));
			for (int k = 0; k < (len - .5f) /2; k++)
			{
				cout << preString;
			}
			cout << _Cells[j][i].getValue();
			for (int k = 0; k < (len + .5f) / 2; k++)
			{
				cout << preString;
			}
			cout << verticalSeperation;
		}
		for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
		{
			cout << endl << horizontalEmptySeperation;
		}
	}
	cout << endl << horizontalSeperation;
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

void Table::grip()
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
				_played = 1;
			}
		}
	}
}

void Table::fusion()
{
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 1; i < _sizeX ; i++)
		{
			if (_Cells[j][i - 1].getValue() == _Cells[j][i].getValue()&& _Cells[j][i - 1].getValue() != 0)
			{
				_Cells[j][i - 1].doubl();
				_Cells[j][i].reset();
				_played = 1;
			}
		}
	}
}


void Table::actionLeft()
{
	grip();
	fusion();
	grip();
	if (_played)
	{
		NextTurn();
	}
}
void Table::actionRight()
{
	RotateGrid(2);
	grip();
	fusion();
	grip();
	RotateGrid(2);
	if (_played)
	{
		NextTurn();
	}
}
void Table::actionUp()
{
	RotateGrid(1);
	grip();
	fusion();
	grip();
	RotateGrid(3);
	if (_played)
	{
		NextTurn();
	}
}
void Table::actionDown()
{
	RotateGrid(3);
	grip();
	fusion();
	grip();
	RotateGrid(1);
	if (_played)
	{
		NextTurn();
	}
}