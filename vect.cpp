#include "vect.h"
#include <math.h>

Vect2::Vect2() : Vect2(0, 0, false)
{
}

Vect2::Vect2(bool abs) : Vect2(0, 0, abs)
{
}

Vect2::Vect2(int x, int y) : Vect2(x, y, false)
{
}

Vect2::Vect2(int x, int y, bool abs)
{
	_x = x;
	_y = y;
	setIfOnlyInAbs(abs);
	makeAbsolute();
}

void Vect2::setIfOnlyInAbs(bool abs)
{
	_abs = abs;
}

int Vect2::x()
{
	return _x;
}

int Vect2::y()
{
	return _y;
}

int Vect2::norme()
{
	return sqrt((_x * _x) + (_y * _y));
}

Vect2 Vect2::normal()
{
	Vect2 newVect2(_x / norme(), _y / norme());
	return newVect2;
}

void Vect2::normalize()
{
	_x = _x / norme();
	_y = _y / norme();
	makeAbsolute();
}

Vect2 Vect2::operator*(int val)
{
	Vect2 newVect2(_x * val, _y * val);
	return newVect2;
}

Vect2 Vect2::operator/(int val)
{
	Vect2 newVect2(_x / val, _y / val);
	return newVect2;
}

int Vect2::operator*(Vect2 otherVect2)
{
	return (_x * otherVect2.x()) + (_y * otherVect2.y());
}

Vect2 Vect2::operator+(Vect2 otherVect2)
{
	Vect2 newVect2(_x + otherVect2.x(), _y + otherVect2.y());
	return newVect2;
}

Vect2 Vect2::operator-(Vect2 otherVect2)
{
	Vect2 newVect2(_x - otherVect2.x(), _y - otherVect2.y());
	return newVect2;
}

void Vect2::operator=(Vect2 otherVect2)
{
	_x = otherVect2.x();
	_y = otherVect2.y();
	makeAbsolute();
}

void Vect2::operator*=(int val)
{
	_x = _x * val;
	_y = _y * val;
	makeAbsolute();
}

void Vect2::operator/=(int val)
{
	_x = _x / val;
	_y = _y / val;
	makeAbsolute();
}

void Vect2::operator+=(Vect2 otherVect2)
{
	_x = _x + otherVect2.x();
	_y = _y + otherVect2.y();
	makeAbsolute();
}

void Vect2::operator-=(Vect2 otherVect2)
{
	_x = _x - otherVect2.x();
	_y = _y - otherVect2.y();
	makeAbsolute();
}

void Vect2::makeAbsolute()
{
	if (_abs)
	{
		if (_x < 0)
		{
			_x = 0;
		}
		if (_y < 0)
		{
			_y = 0;
		}
	}
}