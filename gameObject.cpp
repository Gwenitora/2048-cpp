#include "gameObject.h"
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

GameObject::GameObject()
{
	_border = _dbColor.getBorder();
	_textContent = "";
	_borderRadius = 0;

	_size.setIfOnlyInAbs(true);
	_targetSize.setIfOnlyInAbs(true);

	_speedSize = 0;
	_speedPos = 0;
	_speedColor = 0;
	_pctColor = 1;

	_text = _dbColor.getNumber(0);
	_bg = _dbColor.getNumber(0);
	_targetText = _dbColor.getNumber(0);
	_targetBg = _dbColor.getNumber(0);

	setSpeedColor(.5f);

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

void GameObject::setSpeedColor(float maxSpeed)
{
	_speedColor = maxSpeed;
}

void GameObject::goTo(Vect2 v, bool animated)
{
	if (!animated)
	{
		_pos += (v - _targetPos);
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

void GameObject::setPos(int x, int y) 
{
	_x = x;
	_y = y;
}

void GameObject::draw(SDL_Renderer* renderer, vector<SDL_Texture*> textures)
{
	//int deltaTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - _lastTime).count();
	// calcul puis draw ici !!!
	cout << endl << stoi(_textContent) << " : ";
	_targetBg.printColor(true);
	cout << ": ";
	_targetBg.printColorHex(true);
	if (_targetBg != _dbColor.getNumber(stoi(_textContent)))
	{
		_targetBg = _dbColor.getNumber(stoi(_textContent));
	}

	SDL_Rect cell;
	cell.x = (1280 / 4) + 20 + (145 * _x);
	cell.y = (800 / 8) + 20 + (145 * _y);
	cell.h = 125;
	cell.w = 125;
	TTF_Font* Arial = TTF_OpenFont("Arial/arial.ttf", 48);
	SDL_Color Black = { 0, 0, 0 };
	//SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Arial, _textContent.c_str(), Black);
	//SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect dstrect;
	dstrect.x = (1280 / 4) + 55 + (145 * _x);
	dstrect.y = (800 / 8) + 60 + (145 * _y);
	dstrect.h = 50;
	dstrect.w = 50;
	if(_textContent != "0")
	{
		Color actualColorBg;
		_bg.mixin(_targetBg, &actualColorBg, _pctColor);
		SDL_SetRenderDrawColor(renderer, actualColorBg.r(), actualColorBg.g(), actualColorBg.b(), actualColorBg.a());
		SDL_RenderFillRect(renderer, &cell);
		SDL_RenderCopy(renderer, textures[log2(stoi(_textContent))-1], NULL, &dstrect);
	}
	else {
		SDL_SetRenderDrawColor(renderer, _border.r(), _border.g(), _border.b(), _border.a());
		SDL_RenderFillRect(renderer, &cell);
	}
	//resetDeltaTime();s
}

