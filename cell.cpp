#include "cell.h"


Cell::Cell(int value)
{
	_value = value;
};
Cell::Cell() : Cell(0)
{
};
int Cell::getValue()
{
	return _value;
};