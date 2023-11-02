#pragma once

#include <SDL.h>
#include <vector>
#include "gameObject.h"
#include "table.h"
#include "dbColors.h"
#include "colors.h"

using namespace std;

class Window
{
public:
	Table _table;
	int _sizeX;
	int _sizeY;
	vector<GameObject> _objectList;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	vector<vector<SDL_Rect>> _grid;
<<<<<<< HEAD
	bool _KEYS[322];

	DbColors _dbColors;

	Color _bg;
	Color _emptyCell;
	Color _border;

public:
=======
>>>>>>> 9dafc5de9fabec0c6f9ddcda04d6576632a0bb25
	Window(int sizeX,int sizeY);
	Window();
	void Draw();
	void DrawPlayAgain();
	void DrawGrid();
	void DrawSurface();
};