#include "graphic.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include<SDL_ttf.h>
using namespace std;
Graphic::Graphic()
	{
	SDL_Surface* winSurface;
	SDL_Window* window;
	vector<vector<SDL_Rect>> grid;
	grid.resize(4);
	for (int i = 0; i < 4; i++) {
		grid[i].resize(4);
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
		return ;
	}
	TTF_Init();
	window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 800, SDL_WINDOW_OPENGL);
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		system("pause");
		return ;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	TTF_Font* Arial = TTF_OpenFont("Arial/arial.ttf", 48);
	SDL_Color Black = { 0, 0, 0 };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Arial, "2", Black);
	SDL_Rect backGrid;
	backGrid.x = 1280/4;
	backGrid.y = 800/8;
	backGrid.h = 600;
	backGrid.w = 600;
	winSurface = SDL_GetWindowSurface(window);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	if (!winSurface) {
		cout << "Error getting surface: " << SDL_GetError() << endl;
		system("pause");
		return;
	}
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			grid[j][i].x = (1280 / 4) + 20 + (145 * i);
			grid[j][i].y = (800 / 8) + 20 + (145 * j);
			grid[j][i].h = 125;
			grid[j][i].w = 125;
		}
	}
	SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 205, 193, 180, 255);
	SDL_RenderFillRect(renderer, &backGrid);
	SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			SDL_RenderFillRect(renderer, &grid[j][i]);
			SDL_Rect dstrect;
			dstrect.x = (1280 / 4) + 55 + (145 * i);
			dstrect.y = (800 / 8) + 60 + (145 * j);
			dstrect.h = 50;
			dstrect.w = 50;
			SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		}
	}
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &Message_rect);
	SDL_RenderPresent(renderer);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	//SDL_RenderPresent(renderer);

	system("pause");

	SDL_DestroyWindow(window);

	SDL_Quit();
		
	TTF_Quit();
	return ;
	};