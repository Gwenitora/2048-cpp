#include "gameObject.h"
#include <chrono>
using namespace std;

GameObject::GameObject()
{
	_textContent = "";
	_borderRadius = 0;

	_size.setIfOnlyInAbs(true);
	_targetSize.setIfOnlyInAbs(true);

	resetDeltaTime();
}

void GameObject::setText(string str)
{
	_textContent = str;
}

void GameObject::setBorderRadius(int borderRadius)
{
	_borderRadius = borderRadius;
}

void GameObject::setSpeedPos(int maxSpeed)
{
	_maxSpeedPos = maxSpeed;
}

void GameObject::setSpeedPos(int maxSpeed, int accel)
{
	setSpeedPos(maxSpeed);
	_accelPos = accel;
}

void GameObject::setSpeedSize(int maxSpeed)
{
	_maxSpeedSize = maxSpeed;
}

void GameObject::setSpeedSize(int maxSpeed, int accel)
{
	setSpeedSize(maxSpeed);
	_accelSize = accel;
}

void GameObject::goTo(Vect2 v, bool animated)
{
	if (!animated)
	{
		_size += (v - _targetPos);
	}
	_targetPos = v;
}

void GameObject::moveTo(Vect2 v, bool animated)
{
	if (!animated)
	{
		_pos += v;
	}
	_targetPos += v;
}

void GameObject::resizeTo(Vect2 v, bool animated)
{
	if (!animated)
	{
		_size += (v - _targetSize);
	}
	_targetSize = v;
}

void GameObject::rescaleTo(Vect2 v, bool animated)
{
	if (!animated)
	{
		_size += v;
	}
	_targetSize += v;
}


void GameObject::resetDeltaTime()
{
	_lastTime = chrono::steady_clock::now();
}

void GameObject::draw()
{
	int deltaTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - _lastTime).count();
	// calcul puis draw ici !!!
	resetDeltaTime();
}