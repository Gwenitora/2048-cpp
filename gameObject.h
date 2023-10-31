#pragma once
#include "colors.h"
#include "vect.h"
#include <iostream>
#include <chrono>
using namespace std;

class GameObject
{
public:
	Color _text;
	Color _bg;

private:
	string _textContent;
	int _borderRadius;

	int _accelPos;
	int _speedPos;
	int _maxSpeedPos;

	int _accelSize;
	int _speedSize;
	int _maxSpeedSize;

	Vect2 _pos;
	Vect2 _targetPos;

	Vect2 _size;
	Vect2 _targetSize;

	chrono::steady_clock::time_point _lastTime;

public:
	GameObject();

	void setText(string str);

	void setBorderRadius(int borderRadius);

	void setSpeedPos(int maxSpeed);
	void setSpeedPos(int maxSpeed, int accel);
	void setSpeedSize(int maxSpeed);
	void setSpeedSize(int maxSpeed, int accel);

	void goTo(Vect2 v, bool animated = true);
	void moveTo(Vect2 v, bool animated = true);
	void resizeTo(Vect2 v, bool animated = true);
	void rescaleTo(Vect2 v, bool animated = true);

	void resetDeltaTime();

	void draw();
};