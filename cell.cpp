#include "cell.h"
#include <stdlib.h>

Cell::Cell(int value)
{
    // init la cell
	_value = value;
};
Cell::Cell() : Cell(0)
{
    // si aucune valeur d�finis, init la cell comme �tant vide
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
    // g�n�re une nouvel cellule � partir des r�gle de g�n�ration (9 chance sur 10 d'avoir 2, et 1 chance sur 10 d'avoir 4)
    int is4 = rand() % 10 + 1;
    if (is4 < 10)
    {
        _value = 2;
    }
    else {
        _value = 4;
    }
}