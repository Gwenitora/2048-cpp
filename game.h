#pragma once
#include "table.h"
class Game
{
	Table _table;
	string _text;
	vector<string> _validTexts;
	bool _playAgain;
	void PlayAgain();
public:
	Game();
};