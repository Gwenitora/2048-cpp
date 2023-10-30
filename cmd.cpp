#include "cmd.h"
#include "table.h";

void Cmd::printOnConsole(Table* table, bool cls)
{
	// cr�e une grid custom pour que peu importe la taille de la grille (qu'elle soit carr� ou non)
	// l'espace � l'int�rieur des cases soit le m�me peu importe le chiffre (ou nombre) � l'int�rieur de celles-ci
	if (cls)
	{
		system("CLS");
	}
	cout << "score: " << table->getScore();
	int maxSize = log10(4 * pow(2, (table->_sizeX * table->_sizeY)));
	string preString = " ";
	string verticalSeperation = " | ";
	string horizontalSeperation = " ";
	for (int i = 0; i < (maxSize + 4) * table->_sizeX + 1; i++)
	{
		horizontalSeperation += "-";
	}
	string horizontalEmptySeperation = verticalSeperation;
	for (int i = 0; i < table->_sizeX; i++)
	{
		for (int i = 0; i < maxSize + 1; i++)
		{
			horizontalEmptySeperation += preString;
		}
		horizontalEmptySeperation += verticalSeperation;
	}
	for (int j = 0; j < table->_sizeY; j++)
	{
		cout << endl << horizontalSeperation;
		for (int k = 0; k < ((maxSize + .5f) / 2 - .5f) / 2; k++)
		{
			cout << endl << horizontalEmptySeperation;
		}
		cout << endl << verticalSeperation;
		for (int i = 0; i < table->_sizeX; i++)
		{
			int len = (maxSize - (table->_Cells[j][i].getValue() == 0 ? 1 : log10(table->_Cells[j][i].getValue())));
			for (int k = 0; k < (len - .5f) / 2; k++)
			{
				cout << preString;
			}
			if (table->_Cells[j][i].getValue() == 0)
			{
				cout << " ";
			}
			else
			{
				cout << table->_Cells[j][i].getValue();
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