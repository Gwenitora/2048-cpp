#pragma once
#include "cell.h"
#include <iostream>
#include <vector>
using namespace std;

class Table
{
	vector<vector<Cell>> _Cells;
	int _sizeX;
	int _sizeY;

public:
	Table(int sizeX, int sizeY);
	Table();
	void setCell(int x, int y, Cell cell);
	void setCells(vector<vector<Cell>> cells);
	Cell getCell(int x, int y);
	void ShowGrid();
	void RotateGrid(int repeat);

	void grip();
	void fusion();

	void actionLeft();
	void actionRight();
	void actionUp();
	void actionDown();
};