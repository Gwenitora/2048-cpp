#include "cell.h"
#include <stdlib.h>

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

void Cell::doubl()
{
	_value *= 2;
}
void Cell::divide()
{
	_value /= 2;
}
void Cell::reset()
{
	_value = 0;
}
void Cell::genereNew()
{
    int is4 = rand() % 10 + 1;
    if (is4 < 9)
    {
        _value = 2;
    }
    else {
        _value = 16;
    }
}