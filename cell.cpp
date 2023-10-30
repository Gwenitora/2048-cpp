#include "cell.h"
#include <stdlib.h>

Cell::Cell(int value)
{
    // init la cell
	_value = value;
};
Cell::Cell() : Cell(0)
{
    // si aucune valeur définis, init la cell comme étant vide
};
int Cell::getValue()
{
    // get la valeur de la cell
	return _value;
};

void Cell::doubl()
{
    // double la valeur de la cell
	_value *= 2;
}
void Cell::reset()
{
    // reset la valeur de la cell
	_value = 0;
}
void Cell::genereNew()
{
    // génère une nouvel cellule à partir des règle de génération (9 chance sur 10 d'avoir 2, et 1 chance sur 10 d'avoir 4)
    int is4 = rand() % 10 + 1;
    if (is4 < 10)
    {
        _value = 2;
    }
    else {
        _value = 4;
    }
}