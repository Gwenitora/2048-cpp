#include <conio.h>
#include "table.h"
#include "game.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Game::Game()
{
	bool badKey = true;
	int c = 0;
	while (true)
	{
		_table.ShowGrid();
		badKey = true;
		while (badKey)
		{
			badKey = false;
			c = 0;
			switch ((c = _getch()))
			{
			case KEY_UP:
				_table.actionUp();
				break;
			case KEY_DOWN:
				_table.actionDown();
				break;
			case KEY_RIGHT:
				_table.actionRight();
				break;
			case KEY_LEFT:
				_table.actionLeft();
				break;
			default:
				badKey = true;
				break;
			}
		}
	}
}