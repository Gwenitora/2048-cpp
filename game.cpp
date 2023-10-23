#include "table.h"

class Game
{
	Table* _table;

	Game()
	{
		_table = new Table(4, 4);
	};
};