#pragma once
#include "table.h"
#include "test.h"

class Game
{
	Table _table;
	string _text;
	vector<string> _validTexts;
	bool _playAgain;
	void PlayAgain();
	Integration _test;
public:
	Game();
};