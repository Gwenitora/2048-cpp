#pragma once

#include <SDL.h>
#include <vector>
#include "gameObject.h"

using namespace std;

class Window
{
public:
	int _sizeX;
	int _sizeY;
	vector<GameObject> _objectList;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	vector<vector<SDL_Rect>> _grid;
	Window(int sizeX,int sizeY);
	Window();
	void Draw();
	void DrawGrid();
};