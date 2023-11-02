#pragma once
#include "colors.h"

class DbColors
{
private:
	Color _defaultColor;

	Color _emptyCell;

	Color _2;
	Color _4;
	Color _8;
	Color _16;
	Color _32;
	Color _64;
	Color _128;
	Color _256;
	Color _512;
	Color _1024;
	Color _2048;
	Color _4096;
	Color _8192;
	Color _16384;
	Color _32768;
	Color _65536;
	Color _131072;

	Color _textBlack;
	Color _textWhite;

	Color _border;
	Color _bg;

public:
	DbColors();
	Color getNumber(int val = 0);
	Color getText(int val = 0);
	Color getText(bool black = false);
	Color getBorder();
	Color getBackground();
};