#pragma once
#include "gameObject.h"
class Cell:GameObject
{
private:
	int _value;

public:
	Cell();
	Cell(int value);

	int getValue();
	void doubl();
	void reset();
	void genereNew();
	void setXYGameObject(int x,int y);
	void setTextGameObject(string str);
	void drawGameObject(SDL_Renderer* renderer, vector<SDL_Texture*> textures);
};