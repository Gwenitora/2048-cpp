#include "cell.h"
#include "table.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 
using namespace std;

Table::Table(int sizeX, int sizeY)
{
	//cr�e la table
	_sizeX = sizeX;
	_sizeY = sizeY;
	_lengthAllCoords = _sizeY * _sizeX;
	_inGame = 1;
	_played = 0;
	_score = 0;
	_Cells.resize(_sizeY);
	for (int j = 0; j < _sizeY; j++)
	{
		_Cells[j].resize(_sizeX);
	}
	nextTurn();
}

Table::Table() : Table( 4, 4 )
{
	//cr�e la table XxY
}

void Table::resetAllCells()
{
	//reset toutes les values des cells � 0
	_score = 0;
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			_Cells[j][i].reset();
		}
	}
}

void Table::regen()
{
	//Reg�nere la table(fait un nextTurn pour g�n�rer les deux valeurs de base)
	resetAllCells();
	nextTurn();
}

void Table::gen(int number) 
{
	//Appelle genereNew sur une case vide au hasard(ou plusieurs,d�pend de la valeur number)
	int listSize = _list.size();
	for (int k = 0; k < number; k++) {
		int randomNumber = rand() % (listSize);
		_list[randomNumber]->genereNew();
		for (int j = randomNumber; j < listSize - 1; j++)
		{
			_list[j] = _list[j + 1];
		}
		listSize--;
	}
}

void Table::getEmptyCells()
{
	//push dans _list toutes les cases vides(value = 0)
	_list.clear();
	for (int i = 0; i < _sizeY;i++) {
		for (int j = 0; j < _sizeX; j++) {
			if (_Cells[i][j].getValue() == 0) {
				_list.push_back(&_Cells[i][j]);
			}
		}
	}
}

void Table::nextTurn() {
	//Appelle gen pour g�n�rer sur une ou plusieurs cases(d�pend si toutes les cases sont vides ou non
	//Appelle gameOver et si gameOver renvoie une valeur "vraie"(en l'occurence 1 ou 2)change la valeur de _inGame
	_played = 0;
	getEmptyCells();
	if (_lengthAllCoords == _list.size()) {
		gen(2);
	}
	else {
		gen(1);
	}
	int isTheGameOver = gameOver();
	if (isTheGameOver) {
		_inGame = 0;
	}
	_played = 0;
}

int Table::gameOver() {
	//Regarde si le joueur a atteint 2048
	//Regarde si des mouvements sont possibles(grip et fusion)
	//Sinon renvoie 0 pour que la partie continue
	getEmptyCells();
	_played = 0;
		for (int i = 0; i < _sizeY; i++)
	{
		for (int j = 0; j < _sizeX; j++)
		{
			if (_Cells[i][j].getValue() == 2048) {
				cout << endl <<"Victory";
				return 2;
			}
		}
	} 
	if (_list.size() == 0)
	{
		for (int j = 0; j < _sizeY; j++)
		{
			for (int i = 0; i < _sizeX; i++)
			{
				if (j < _sizeY - 1)
				{
					if (_Cells[j][i].getValue() == _Cells[j + 1][i].getValue())
					{
						_played = 1;
					}
				}
				if (i < _sizeX - 1)
				{
					if (_Cells[j][i].getValue() == _Cells[j][i + 1].getValue())
					{
						_played = 1;
					}
				}
			}
		}
		if(!_played)
		{
			cout << endl << "Defeat";
			return 1;
		}
	}
	return 0;
}

void Table::showGrid()
{
	//cr�e une grid custom pour que peu importe la taille de la grille(qu'elle soit carr� ou non)
	//l'espace � l'int�rieur des cases soit le m�me peu importe le chiffre(ou nombre) � l'int�rieur de celles-ci
	//system("CLS");
	int maxSize = log10(4 * pow(2, (_sizeX * _sizeY))) - .5f;
	string preString = " ";
	string verticalSeperation = " | ";
	string horizontalSeperation = " ";
	for (int i = 0; i < (maxSize + 4) * _sizeX + 1; i++)
	{
		horizontalSeperation += "-";
	}
	string horizontalEmptySeperation = verticalSeperation;
	for (int i = 0; i < _sizeX; i++)
	{
		for (int i = 0; i < maxSize +1; i++)
		{
			horizontalEmptySeperation += preString;
		}
		horizontalEmptySeperation += verticalSeperation;
	}
	for (int j = 0; j < _sizeY; j++)
	{
		cout << endl << horizontalSeperation;
		for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
		{
			cout << endl << horizontalEmptySeperation;
		}
		cout << endl << verticalSeperation;
		for (int i = 0; i < _sizeX; i++)
		{
			int len = (maxSize - (_Cells[j][i].getValue() == 0 ? 1 : log10(_Cells[j][i].getValue())));
			for (int k = 0; k < (len - .5f) /2; k++)
			{
				cout << preString;
			}
			if (_Cells[j][i].getValue() == 0)
			{
				cout << " ";
			}
			else
			{
				cout << _Cells[j][i].getValue();
			}
			for (int k = 0; k < (len + .5f) / 2; k++)
			{
				cout << preString;
			}
			cout << verticalSeperation;
		}
		for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
		{
			cout << endl << horizontalEmptySeperation;
		}
	}
	cout << endl << horizontalSeperation;
}

void Table::setCell(int x, int y, Cell cell)
{
	//set une cell � des coordonn�es sp�cifiques
	_Cells[y][x] = cell;
}

void Table::setCells(vector<vector<Cell>> cells)
{
	//set un tableau entier de cell
	_Cells = cells;
}

Cell Table::getCell(int x, int y)
{
	//retourne la cell demand�e
	return _Cells[y][x];
}

void Table::rotateGrid(int repeat)
{
	//tourne la grille dans le sens horaire
	Table actual = Table(_sizeX, _sizeY);
	actual.setCells(_Cells);
	for (int k = 0; k < repeat; k++)
	{
		Table otherTable = Table(actual._sizeY, actual._sizeX); 
		for (int j = 0; j < actual._sizeY; j++)
		{
			for (int i = 0; i < actual._sizeX; i++)
			{
				otherTable.setCell(j, i, actual.getCell(i, actual._sizeY - 1 - j));
			}
		}
		actual = otherTable;
	}
	_sizeX = actual._sizeX;
	_sizeY = actual._sizeY;
	_Cells = actual._Cells;
}

void Table::grip()
{
	//d�place vers la gauche les cases avec une valeur
	for (int j = 0; j < _sizeY; j++)
	{
		int offset = 0;
		for (int i = 0; i < _sizeX; i++)
		{
			if (getCell(i, j).getValue() == 0)
			{
				offset++;
			}
			else if (offset != 0)
			{
				setCell(i - offset, j, getCell(i, j));
				_Cells[j][i].reset();
				_played = 1;
			}
		}
	}
}

void Table::fusion()
{
	//fusionne deux cases : si deux cases sont coll�es(direction horizontale) et de m�me valeur,
	// la case de gauche s'ajoutera la valeur de celle de droite et celle-ci sera reset
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 1; i < _sizeX ; i++)
		{
			if (_Cells[j][i - 1].getValue() == _Cells[j][i].getValue()&& _Cells[j][i - 1].getValue() != 0)
			{
				_Cells[j][i - 1].doubl();
				_Cells[j][i].reset();
				_score += _Cells[j][i - 1].getValue();
				_played = 1;
			}
		}
	}
}


void Table::actionLeft(bool lockedWithoutGen)
{
	//mouvement vers la gauche(d�placement/fusion/d�placement 
	//puis regarde si un coup s'est jou�,si oui appelle nextTurn qui reg�n�re une value gr�ce � Gen
	grip();
	fusion();
	grip();
	if (!lockedWithoutGen && _played)
	{
		nextTurn();
	}
}
void Table::actionRight(bool lockedWithoutGen)
{
	//Pareil mais vers la droite
	//on fait tourner la grille de 180�
	rotateGrid(2);
	grip();
	fusion();
	grip();
	rotateGrid(2);
	if (!lockedWithoutGen && _played)
	{
		nextTurn();
	}
}
void Table::actionUp(bool lockedWithoutGen)
{
	//Pareil mais vers le haut
	//on fait tourner la grille de 270�
	rotateGrid(3);
	grip();
	fusion();
	grip();
	rotateGrid(1);
	if (!lockedWithoutGen && _played)
	{
		nextTurn();
	}
}
void Table::actionDown(bool lockedWithoutGen)
{
	//Pareil mais vers le bas
	//on fait tourner la grille de 90�
	rotateGrid(1);
	grip();
	fusion();
	grip();
	rotateGrid(3);
	if (!lockedWithoutGen && _played)
	{
		nextTurn();
	}
}

int Table::getScore()
{
	return _score;
}