#include "cell.h"
#include "table.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include "Cmd.h"
using namespace std;

Table::Table(int sizeX, int sizeY)
{
	// crée la table
	_sizeX = sizeX;
	_sizeY = sizeY;
	_lengthAllCoords = _sizeY * _sizeX;
	_inGame = 1;
	_played = 0;
	_Cells.resize(_sizeY);
	for (int j = 0; j < _sizeY; j++)
	{
		_Cells[j].resize(_sizeX);
	}
	NextTurn();
}

Table::Table() : Table( 4, 4 )
{
	// crée la table XxY à a taille 4x4
}

void Table::resetAllCells()
{
	// reset toutes les values des cells à 0
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			_Cells[j][i].reset();
		}
	}
}

void Table::Regen()
{
	// Regènere la table (fait un nextTurn pour générer les deux valeurs de base)
	resetAllCells();
	NextTurn();
}

void Table::Gen(int number) 
{
	// Appelle genereNew sur une case vide au hasard (ou plusieurs,dépend de la valeur number)
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
	// push dans _list toutes les cases vides (value = 0)
	_list.clear();
	for (int i = 0; i < _sizeY;i++) {
		for (int j = 0; j < _sizeX; j++) {
			if (_Cells[i][j].getValue() == 0) {
				_list.push_back(&_Cells[i][j]);
			}
		}
	}
}

void Table::NextTurn() {
	// Appelle gen pour générer sur une ou plusieurs cases(dépend si toutes les cases sont vides ou non
	_played = 0;
	getEmptyCells();
	if (_lengthAllCoords == _list.size()) {
		Gen(2);
	}
	else {
		Gen(1);
	}
	// Appelle gameOver et si gameOver renvoie une valeur "vraie" (en l'occurence 1 ou 2) change la valeur de _inGame
	int isTheGameOver = gameOver();
	if (isTheGameOver) {
		_inGame = 0;
	}
	_played = 0;
}

int Table::gameOver() {
	// Regarde si le joueur a atteint 2048
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
	// Regarde si des mouvements sont possibles (grip et fusion)
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
	// Sinon renvoie 0 pour que la partie continue
	return 0;
}

void Table::setCell(int x, int y, Cell cell)
{
	// set une cell à des coordonnées spécifiques
	_Cells[y][x] = cell;
}

void Table::setCells(vector<vector<Cell>> cells)
{
	// set un tableau entier de cell
	_Cells = cells;
}

Cell Table::getCell(int x, int y)
{
	// retoure la cell en coordonée (x, y)
	return _Cells[y][x];
}

void Table::RotateGrid(int repeat)
{
	// tourne la grille dans le sens horaire
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
	// déplace vers la gauche les cases avec une valeur
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
	// fusionne deux cases : si deux cases sont collées (direction horizontale) et de même valeur,
	// la case de gauche s'ajoutera la valeur de celle de droite et cette dernière sera reset
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 1; i < _sizeX ; i++)
		{
			if (_Cells[j][i - 1].getValue() == _Cells[j][i].getValue()&& _Cells[j][i - 1].getValue() != 0)
			{
				_Cells[j][i - 1].doubl();
				_Cells[j][i].reset();
				_played = 1;
			}
		}
	}
}


void Table::actionLeft(bool lockedWithoutGen)
{
	// mouvement vers la gauche (déplacement/fusion/déplacement)
	// puis regarde si un coup s'est joué, si oui appelle nextTurn qui regénère une value grâce à Gen
	grip();
	fusion();
	grip();
	if (!lockedWithoutGen && _played)
	{
		NextTurn();
	}
}
void Table::actionRight(bool lockedWithoutGen)
{
	// Pareil mais vers la droite
	// pour cela, on fait tourner la grille de 180° avant et après les actions
	RotateGrid(2);
	grip();
	fusion();
	grip();
	RotateGrid(2);
	if (!lockedWithoutGen && _played)
	{
		NextTurn();
	}
}
void Table::actionUp(bool lockedWithoutGen)
{
	// Pareil mais vers le haut
	// pour cela, on fait tourner la grille de 270° avant les actions, puis de 90° après
	RotateGrid(3);
	grip();
	fusion();
	grip();
	RotateGrid(1);
	if (!lockedWithoutGen && _played)
	{
		NextTurn();
	}
}
void Table::actionDown(bool lockedWithoutGen)
{
	// Pareil mais vers le haut
	// pour cela, on fait tourner la grille de 90° avant les actions, puis de 270° après
	RotateGrid(1);
	grip();
	fusion();
	grip();
	RotateGrid(3);
	if (!lockedWithoutGen && _played)
	{
		NextTurn();
	}
}

void Table::createCopy(Table gettingTable)
{
	// créer une copie complète de gettingTable vers la table actuel (changement de taille compris dans le processus)
	resetAllCells();

	_sizeX = gettingTable._sizeX;
	_sizeY = gettingTable._sizeY;

	_Cells.resize(_sizeY);
	for (int j = 0; j < _sizeY; j++)
	{
		_Cells[j].resize(_sizeX);
	}

	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			setCell(i, j, Cell(gettingTable.getCell(i, j).getValue()));
		}
	}
}

bool Table::compare(Table tableToCompare)
{
	// vérifie si le contenu de tableToCompare et de la table actuel sont les même, renvoie tru si vrai
	if (_sizeX != tableToCompare._sizeX)
	{
		return false;
	}
	if (_sizeY != tableToCompare._sizeY)
	{
		return false;
	}

	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			if (getCell(i, j).getValue() != tableToCompare.getCell(i, j).getValue())
			{
				return false;
			}
		}
	}
	return true;
}

int Table::getScore()
{
	// calcul du score du tableau
	int score = 0;
	for (int j = 0; j < _sizeY; j++)
	{
		for (int i = 0; i < _sizeX; i++)
		{
			score += getCell(i, j).getValue();
		}
	}
	return score;
}

void Table::ShowGrid(bool cls)
{
	Cmd::printOnConsole(this, cls);
}