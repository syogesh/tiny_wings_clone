#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

const int MAX_ENTITIES = 50;
const int MAX_HILLS = 100;
const int HILL_WIDTH = 10;

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
const int LEVEL_HEIGHT = 640;

const int HERO_VEL = 3;

extern SDL_Renderer* mainRenderer;
extern SDL_Window* mainWindow;

extern SDL_Rect camera;

typedef enum
{
	COMPONENT_NONE = 0,
	COMPONENT_POSITION = 1 << 0,
	COMPONENT_VELOCITY = 1 << 1,
	COMPONENT_SPRITE = 1 << 2
} Component;

const int MOVEMENT_MASK = (COMPONENT_POSITION | COMPONENT_VELOCITY);