#pragma once

#include "Main.h"
#include "Texture.h"
#include "Position.h"
#include "Velocity.h"
#include "Sprite.h"
#include "Terrain.h"

class Game
{
public:
	Game();
	~Game();

	bool initialize();
	bool loadMedia();
	bool loadMap();
	void destruct();

	void displayBackground();
	void drawTerrain();
	void reloadBackground(); //trash function, just for testing

	int createEntity();
	void destroyEntity(int i);

	void createHero();
	void heroEventHandler(SDL_Event& event);

	void movementSystem();
	void animationSystem();
	void gravitySystem();
	void centerCamera(SDL_Rect& camera);



private:

	Texture background;
	Texture backgroundNoise;

	std::vector<int> componentMasks;
	std::vector<Position> componentPositions;
	std::vector<Velocity> componentVelocities;
	std::vector<Sprite> componentSprites;

	int heroNum;

	int scrollX;
	int scrollY;

	Terrain terrain;
	int leftRender;
	int rightRender;

};

