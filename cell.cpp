#include "cell.h"

class Cell
{
	int _value;

	Cell(int value)
	{
		_value = value;
	};

	int getValue()
	{
		return _value;
	};
};