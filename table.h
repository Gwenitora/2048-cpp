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
	void ShowGrid();
};