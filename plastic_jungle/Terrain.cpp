#include "Terrain.h"

Terrain::Terrain()
{
	offset = 0;
	generateHills();
}

void Terrain::generateHills()
{
	//sergey implementation
	int minDx = 160;
	int minDy = 20;
	int rangeDx = 80;
	int rangeDy = 40;

	int x = -minDx;
	int y = SCREEN_HEIGHT/2;

	int dy, ny;
	int sign = 1;
	int paddingTop = 20;
	int paddingBottom = 20;

	SDL_Point tempPoint;
	tempPoint.x = 1;
	tempPoint.y = SCREEN_HEIGHT/2;
	point[0] = tempPoint;

	for (int i = 1; i < MAX_HILLS; ++i)
	{
		tempPoint.x += rand() % rangeDy + minDx;
		while (1)
		{
			dy = rand() % rangeDy + minDy;
			ny = y + dy*sign;
			if (ny < SCREEN_HEIGHT - paddingTop && ny > paddingBottom)
			{
				break;
			}
		}
		tempPoint.y = ny + 150;
		sign *= -1;
		point[i] = tempPoint;
	}

	
}

SDL_Point* Terrain::getPoints()
{
	SDL_Point* pointer = point;
	return pointer;
}

