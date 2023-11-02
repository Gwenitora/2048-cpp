#include "window.h"
#include "colors.h"
#include <iostream>
#include <SDL.h>
#include <vector>
using namespace std;

Window::Window(int sizeX,int sizeY) {
	 _sizeX = sizeX;
	 _sizeY = sizeY;
	 _window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _sizeX, _sizeY, SDL_WINDOW_OPENGL);
	 _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	 _bg = _dbColors.getBackground();
	 _emptyCell = _dbColors.getNumber();
	 _border = _dbColors.getBorder();

	 for (int i = 0; i < 322; i++) {
		 _KEYS[i] = false;
	 }
	 SDL_Surface* winSurface;
	 if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		 cout << "Error initializing SDL: " << SDL_GetError() << endl;
		 system("pause");
		 return;
	 }
	 _grid.resize(4);
	 for (int i = 0; i < 4; i++) {
		 _grid[i].resize(4);
	 }
	 if (!_window) {
		 cout << "Error creating window: " << SDL_GetError() << endl;
		 system("pause");
		 return;
	 }
	 SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
	 winSurface = SDL_GetWindowSurface(_window);
	 if (!winSurface) {
		 cout << "Error getting surface: " << SDL_GetError() << endl;
		 system("pause");
		 return;
	 }
	 SDL_SetRenderDrawColor(_renderer, _bg.r(), _bg.g(), _bg.b(), _bg.a());
	 SDL_RenderClear(_renderer);

	 DrawGrid();
	 Draw();
	 GetKey();
	 SDL_RenderPresent(_renderer);

	 //SDL_DestroyWindow(_window);

	 //SDL_Quit();
	 return;
}

Window::Window() : Window(1280, 800) {

}

void Window::DrawGrid() {
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			_grid[j][i].x = (1280 / 4) + 20 + (145 * i);
			_grid[j][i].y = (800 / 8) + 20 + (145 * j);
			_grid[j][i].h = 125;
			_grid[j][i].w = 125;
		}
	}
	SDL_Rect backGrid;
	backGrid.x = 1280 / 4;
	backGrid.y = 800 / 8;
	backGrid.h = 600;
	backGrid.w = 600;
	SDL_SetRenderDrawColor(_renderer, _emptyCell.r(), _emptyCell.g(), _emptyCell.b(), _emptyCell.a());
	SDL_RenderFillRect(_renderer, &backGrid);
	SDL_SetRenderDrawColor(_renderer, _border.r(), _border.g(), _border.b(), _border.a());
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			SDL_RenderFillRect(_renderer, &_grid[j][i]);
		}
	}
}

void Window::Draw() {
	for (int i = 0; i < _objectList.size(); i++)
	{
		_objectList[i].draw();
	}
}

void Window::GetKey() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			//_Game = 0;
			break;
		case SDL_KEYDOWN:
			_KEYS[event.key.keysym.sym] = true;
			HandleInput();
			break;
		case SDL_KEYUP:
			_KEYS[event.key.keysym.sym] = false;
			break;
		default:
			break;
		}
	}
}

void Window::HandleInput() {
	cout << SDLK_LEFT;
	if (_KEYS[SDLK_LEFT]) {
		_table.actionLeft();
	}
	if (_KEYS[SDLK_RIGHT]) { 
		_table.actionRight();
		}
	if (_KEYS[SDLK_UP]) { 
		_table.actionUp();
	}
	if (_KEYS[SDLK_DOWN]) { 
		_table.actionDown();
	}
}