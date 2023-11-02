#pragma once
#include "colors.h"
#include "vect.h"
#include <iostream>
#include <chrono>
#include <SDL.h>
#include<SDL_ttf.h>
#include <vector>
#include <string>
using namespace std;

class GameObject
{
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

	float _pctColor;
	Color _text;
	Color _targetText;
	Color _bg;
	Color _targetBg;

	chrono::steady_clock::time_point _lastTime;

public:
	int _x;
	int _y;
	GameObject();

	void setText(string str);

	void setBorderRadius(int borderRadius);
	void setPos(int x, int y);
	void setSpeedPos(int maxSpeed);
	void setSpeedPos(int maxSpeed, int accel);
	void setSpeedSize(int maxSpeed);
	void setSpeedSize(int maxSpeed, int accel);

	void goTo(Vect2 v, bool animated = true);
	void moveTo(Vect2 v, bool animated = true);
	void resizeTo(Vect2 v, bool animated = true);
	void rescaleTo(Vect2 v, bool animated = true);

	void resetDeltaTime();

	void draw( SDL_Renderer* renderer, vector<SDL_Texture*> textures);
};