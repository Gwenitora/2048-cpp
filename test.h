#pragma once
#include "table.h"

class Integration
{
public:
	Table _starting;
	Table _left;
	Table _right;
	Table _top;
	Table _bottom;

	Table _startingNoMoves;

	Table _startingDoubleFusion;
	Table _leftDoubleFusion;
	Table _rightDoubleFusion;
	Table _topDoubleFusion;
	Table _bottomDoubleFusion;

	int _loadingMax;
	int _loaded;
	int _rotationState;

public:
	Integration();
	bool testing();
	void printLoadingBar();
};