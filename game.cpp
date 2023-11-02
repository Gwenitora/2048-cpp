#include <conio.h>
#include "table.h"
#include "game.h"
#include <Windows.h>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#undef max
using namespace std;

Game::Game()
{
	_validTexts = { "y", "yes" };
	_playAgain = true;
	cout << "Do you want to play on the console?(y/n)" << endl;
	cin >> _text;
	if (_text == _validTexts[0] || _text == _validTexts[1])
	{
		cmdGame();
	}
	else {
		graphicGame();
	}
}

void Game::playAgain()
{
	cout << endl << "Do you want to play again?(y/n) ";
	cin >> _text;
	if (_text == _validTexts[0] || _text == _validTexts[1])
	{
		_playAgain = true;
		_table._inGame = 1;
		_table.regen();
	}
	else {
		_playAgain = false;
	}
}

void Game::cmdGame() {
	//if (!_test.testing())
	//{
	//	return;
	//}
	int KeyDowned = 0;
	chrono::steady_clock::time_point timer = chrono::steady_clock::now();
	while (_playAgain)
	{
		_table.showGrid();
		while (_table._inGame)
		{
			while (!KeyDowned)
			{
				timer = chrono::steady_clock::now();
				if (GetKeyState(VK_UP) == -127 || GetKeyState(VK_UP) == -128)
				{
					_table.actionUp();
					KeyDowned = 1;
				}
				else if (GetKeyState(VK_DOWN) == -127 || GetKeyState(VK_DOWN) == -128)
				{
					_table.actionDown();
					KeyDowned = 2;
				}
				else if (GetKeyState(VK_LEFT) == -127 || GetKeyState(VK_LEFT) == -128)
				{
					_table.actionLeft();
					KeyDowned = 3;
				}
				else if (GetKeyState(VK_RIGHT) == -127 || GetKeyState(VK_RIGHT) == -128)
				{
					_table.actionRight();
					KeyDowned = 4;
				}
			}
			//cout << chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - timer).count() << endl;
			_table.showGrid();
			while (KeyDowned)
			{
				if ((GetKeyState(VK_UP) == 0 || GetKeyState(VK_UP) == 1) && KeyDowned == 1)
				{
					KeyDowned = 0;
				}
				else if ((GetKeyState(VK_DOWN) == 0 || GetKeyState(VK_DOWN) == 1) && KeyDowned == 2)
				{
					KeyDowned = 0;
				}
				else if ((GetKeyState(VK_LEFT) == 0 || GetKeyState(VK_LEFT) == 1) && KeyDowned == 3)
				{
					KeyDowned = 0;
				}
				else if ((GetKeyState(VK_RIGHT) == 0 || GetKeyState(VK_RIGHT) == 1) && KeyDowned == 4)
				{
					KeyDowned = 0;
				}
			}
		}
		playAgain();
	}
}

void Game::graphicGame() {
	Window _window;
	int keyDownSDL = 0;
	int quit = 0;
	vector<vector<Cell>> tableSDL;
	while (_playAgain)
	{
		keyDownSDL = 0;
		_window.drawSurface();
		SDL_PumpEvents();
		SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
		_table.showGrid();
		_window.drawGrid();
		_window.drawScore(_table);
		tableSDL.resize(4);
		for (int j = 0; j < 4; j++)
		{
			tableSDL[j].resize(4);
			for (int i = 0; i < 4; i++)
			{
				Cell cell = _table.getCell(i, j);
				tableSDL[j][i] = cell;
				cell.setXYGameObject(i, j);
				cell.setTextGameObject(to_string((_table.getCell(i, j)).getValue()));
				_window._objectList.push_back(cell);
			}
		}
		_window.draw();
		while (_table._inGame)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					_table._inGame = 0;
					_playAgain = 0;
					quit = 1;
					break;
				case SDL_KEYDOWN:
					if (keyDownSDL) {
						break;
					}
					keyDownSDL = 1;
					switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						_table.actionLeft();
						break;
					case SDLK_RIGHT:
						_table.actionRight();
						break;
					case SDLK_UP:
						_table.actionUp();
						break;
					case SDLK_DOWN:
						_table.actionDown();
						break;
					default:
						break;
					}
					for (int j = 0; j < 4; j++)
					{
						for (int i = 0; i < 4; i++)
						{
							tableSDL[j][i].setXYGameObject(i, j);
							tableSDL[j][i].setTextGameObject(to_string((_table.getCell(i, j)).getValue()));
							_window._objectList.push_back(tableSDL[j][i]);
						}
					}
					_table.showGrid();
					_window.drawScore(_table);
					_window.draw();
					break;
				case SDL_KEYUP:
					keyDownSDL = 0;
					break;
				default:
					break;
				}
			}
		}
		if (!quit)
		{
			playAgainSDL(_window);
		}
	}
}

void Game::playAgainSDL(Window window)
{
	window.drawPlayAgain();
	bool loop = true;
	while (loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (SDL_MOUSEBUTTONDOWN == event.type) {
				if (SDL_BUTTON_LEFT == event.button.button) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					if (x >= 1280 / 6 + 100 && x <= (1280 / 6 + 100) + 200 && y >= 800 / 5 + 50 && y <= (800 / 5 + 50) + 200) {
						_playAgain = 1;
						_table._inGame = 1;
						_table.regen();
						loop = false;
						break;
					}
					else if (x >= 1280 / 6 + 500 && x <= (1280 / 6 + 500) + 200 && y >= 800 / 5 + 50 && y <= (800 / 5 + 50) + 200) {
						_playAgain = 0;
						loop = false;
						break;
					}
				}
			}
		}
	}
}