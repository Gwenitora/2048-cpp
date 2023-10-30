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

	// test d'integration
	if (!_test.testing())
	{
		return;
	}
	int KeyDowned = 0;

	// boucle de jeu
	while(_playAgain)
	{
		_table.ShowGrid();
		while (_table._inGame)
		{
			// attends qu'une clef valide soit presser
			while (!KeyDowned)
			{
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
			_table.ShowGrid();

			// attends que la clef presser soit relacher
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

// propose un redémarrage du jeu
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