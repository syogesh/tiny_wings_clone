#pragma once

#include "Main.h"

class Position;

class Terrain
{
public:
	Terrain();
	SDL_Point* getPoints();
private:
	int offset;
	SDL_Point point[MAX_HILLS];
	void generateHills();
};