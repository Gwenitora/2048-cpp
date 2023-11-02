#pragma once
#include "table.h"
#include "test.h"
#include "window.h"
#include "gameObject.h"
class Game
{
	Table _table;
	string _text;
	vector<string> _validTexts;
	bool _playAgain;
	void PlayAgain();
	void PlayAgainSDL(Window window);
	Integration _test;
	void CmdGame();
	void GraphicGame();
public:
	Game();
};