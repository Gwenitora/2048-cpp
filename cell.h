#pragma once

class Cell
{
private:
	int _value;

public:
	Cell();
	Cell(int value);

	int getValue();
	
	void doubl();
	void divide();
	void reset();
	void genereNew();
};