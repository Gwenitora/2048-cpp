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
	bool _KEYS[322];

	DbColors _dbColors;

	Color _bg;
	Color _emptyCell;
	Color _border;

public:
	Window(int sizeX,int sizeY);
	Window();
	void Draw();
	void DrawPlayAgain();
	void DrawGrid();
	void DrawSurface();
};