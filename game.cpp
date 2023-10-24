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
			cout << _getch();
			switch ((c = _getch()))
			{
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
			case KEY_RIGHT:
				break;
			case KEY_LEFT:
				break;
			default:
				badKey = true;
				break;
			}
		}
	}
}