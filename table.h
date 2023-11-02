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
	vector<Cell*> _list;
	int _score;

public:
	Table(int sizeX, int sizeY);
	Table();
	void resetAllCells();
	void regen();
	void setCell(int x, int y, Cell cell);
	void setCells(vector<vector<Cell>> cells);
	Cell getCell(int x, int y);
	void showGrid();
	void rotateGrid(int repeat);
	void gen(int number);
	void grip();
	int gameOver();
	void fusion();
	void getEmptyCells();
	void nextTurn();
	void actionLeft(bool lockedWithoutGen = false);
	void actionRight(bool lockedWithoutGen = false);
	void actionUp(bool lockedWithoutGen = false);
	void actionDown(bool lockedWithoutGen = false);
	int getScore();
};