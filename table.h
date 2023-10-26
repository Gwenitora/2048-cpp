#pragma once
#include "cell.h"
#include <iostream>
#include <vector>
using namespace std;
class Game;
class Table
{
public:
	int _inGame;
	vector<vector<Cell>> _Cells;

private:
	int _sizeX;
	int _sizeY;
	int _lengthAllCoords;
	int _played;

public:
	void Regen();
	Table(int sizeX, int sizeY);
	Table();
	void setCell(int x, int y, Cell cell);
	void setCells(vector<vector<Cell>> cells);
	Cell getCell(int x, int y);
	void ShowGrid();
	void RotateGrid(int repeat);
	void Gen(int number, vector<int> list);
	void grip();
	int gameOver();
	void fusion();
	vector<int> getEmptyCells(vector<vector<Cell>> table);
	void nextTurn();
	void actionLeft();
	void actionRight();
	void actionUp();
	void actionDown();
	Table createCopy();
};