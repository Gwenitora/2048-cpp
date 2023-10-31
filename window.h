#pragma once

#include <SDL.h>
#include <vector>
#include "gameObject.h"
#include "table.h"

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
	Window(int sizeX,int sizeY);
	Window();
	void Draw();
	void DrawGrid();
	void GetKey();
	void HandleInput();
};