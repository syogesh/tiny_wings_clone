#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

#include "Game.h"

using namespace std;

SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

int main (int argc, char* args[]) {

	srand(time(0));

	Game game;
	if (!game.initialize())
	{
		cout << "Game couldn't initialize\n";
		return 1;
	}

	if (!game.loadMedia())
	{
		cout << "Game couldn't load media\n";
		return 1;
	}
	SDL_SetRenderTarget(mainRenderer, NULL);


	game.createHero();

	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		//game.gravitySystem();

		while(SDL_PollEvent(&event) != 0)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_RETURN:
							game.reloadBackground();
							break;
					}
			}

			game.heroEventHandler(event);
		}
		//game.background.setSelfAsRenderTarget();

		//SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0x42, 0x00, 0xFF);
		SDL_RenderClear(mainRenderer);
		game.displayBackground();
		game.drawTerrain();
		game.movementSystem();
		game.animationSystem();
		SDL_RenderPresent(mainRenderer);
		game.centerCamera(camera);


		
		//SDL_RenderFillRect(mainRenderer, &screen);

		
	}

	game.destruct();


	return 0;
}
