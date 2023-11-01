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
	cout << "Do you want to play on the console?(y/n)"<<endl;
	cin >> _text;
	if (_text == _validTexts[0] || _text == _validTexts[1])
	{
		CmdGame();
	}
	else {
		GraphicGame();
	}
}

void Game::PlayAgain() 
{
	cout <<endl<< "Do you want to play again?(y/n) ";
	cin >> _text;
	if (_text == _validTexts[0] || _text == _validTexts[1])
	{
		_playAgain = true;
		_table._inGame = 1;
		_table.Regen();
	}
	else {
		_playAgain = false;
	}
}

void Game::CmdGame() {
	//if (!_test.testing())
	//{
	//	return;
	//}
	int KeyDowned = 0;
	chrono::steady_clock::time_point timer = chrono::steady_clock::now();
	while (_playAgain)
	{
		_table.ShowGrid();
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
			_table.ShowGrid();
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
		PlayAgain();
	}
}

void Game::GraphicGame() { 
	Window _window;
	int keyDownSDL = 0;
	while (_playAgain)
	{
		SDL_PumpEvents();
		SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
		_table.ShowGrid();
		_window.DrawGrid();
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if ((_table.getCell(i, j)).getValue() != 0) {
					GameObject Cell;
					Cell._x = i;
					Cell._y = j;
					Cell.setText(to_string((_table.getCell(i, j)).getValue()));
					_window._objectList.push_back(Cell);
				}
			}
		}
		_window.Draw();
		while (_table._inGame)
		{
				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					switch (event.type) {
					case SDL_QUIT:
						//_Game = 0;
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
								if ((_table.getCell(i, j)).getValue() != 0) {
									GameObject Cell;
									Cell._x = i;
									Cell._y = j;
									Cell.setText(to_string((_table.getCell(i, j)).getValue()));
									_window._objectList.push_back(Cell);
								}
							}
						}
						_table.ShowGrid();
						_window.DrawGrid();
						_window.Draw();
						break;
					case SDL_KEYUP:
						keyDownSDL = 0;
						break;
					default:
						break;
					}
				}
		}
		PlayAgain();
	}
}
