#include <conio.h>
#include "table.h"
#include "game.h"
#include <Windows.h>
#include <chrono>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Game::Game()
{
	_validTexts = { "y", "yes" };
	_playAgain = true;
	int KeyDowned = 0;
	chrono::steady_clock::time_point timer = chrono::steady_clock::now();
	while(_playAgain)
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

void ClearBuffer() 
{
	while ( true )
	{
		char c;
		cin >> c;
		if (c == '\n')
			break;
	}
}

void Game::PlayAgain() 
{
	cout <<endl<< "Do you want to play again?(y/n) ";
	cin >> _text;
	//ClearBuffer();
	if (_text == _validTexts[0] || _text == _validTexts[1])
	{
		_playAgain = true;
		_table._inGame = 1;
		_table.Regen();
	}
	else {
		_playAgain = false;
	}
	//_text.clear();
	
	//cin.ignore(INT_MAX);
}