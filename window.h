#pragma once

#include <SDL.h>
#include <vector>
#include "gameObject.h"
#include "table.h"
#include "dbColors.h"
#include "colors.h"
#include <SDL_image.h>
using namespace std;

class Window
{
public:
	Table _table;
	int _sizeX;
	int _sizeY;
	vector<Cell> _objectList;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	vector<vector<SDL_Rect>> _grid;
	vector<SDL_Texture*> _textures;
	DbColors _dbColors;
	vector<string> _path;
	Color _bg;
	Color _emptyCell;
	Color _border;
	TTF_Font* _Arial;
	SDL_Color _Score;
	SDL_Rect _rectScore;
public:
	Window(int sizeX,int sizeY);
	Window();
	void draw();
	void drawplayAgain();
	void drawGrid();
	void drawSurface();
	void drawScore(Table table);
};