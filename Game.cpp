#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

//Screen parameters
const int SCR_WIDTH = 960;
const int SCR_HEIGHT = 640;
const int SCR_BPP = 32;

// Constructors/Destructors
//  

Game::Game () {
initAttributes();
}

Game::~Game () { }


void Game::initAttributes () {
}

bool Game::init ()
{
	// Chack that if SDL can be initilized
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}

	// Main screen draw part
	screen = SDL_SetVideoMode(SCR_WIDTH,SCR_HEIGHT,SCR_BPP,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if ( screen == NULL )
	{
	    printf("Unable to set 960x640 video: %s\n", SDL_GetError());
	    exit(1);
	}

	SDL_WM_SetCaption("Bomberman - RetroGame by Yuci", "");
	atexit(SDL_Quit);

    printf("+++++++++ END +++++++++++\n");
    return true;
}

// Draw images
void Game::DrawIMG(SDL_Surface *img, SDL_Surface *screen, int x, int y)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(img, NULL, screen, &dest);
}

void Game::gameLoop ()
{
    printf("+++++++++ gameLoop () +++++++++++\n");
    int done = 0;
	// Keys variable
	Uint8* Keys;
	// Player and Map objects
	Player player(this);

    	// Load the tiles which will be used
    	SDL_Surface *walls, *solid;
    	walls = SDL_LoadBMP("brick.bmp");
    	solid = SDL_LoadBMP("solid.bmp");
    	if(!walls || !solid)
    	{
    		printf("Unable to load bitmap: %s or %s\n", "brick.bmp", "solid.bmp");
    	    exit(1);
    	}

    	while(done == 0)
    	{
    		while ( SDL_PollEvent(&event) )
            {
    			if (event.type == SDL_QUIT )
    			{
    				done = 1;
    			}
    		}

    		// Get the current keypress
    		Keys = SDL_GetKeyState(0);

    		// If escape was pressed
    		if( Keys[SDLK_ESCAPE] )
    		{
    			done = 1;
    		}

    		// Clear the whole screen
    		SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0) );

    		// Draw the tiles via loop
            for (int r = 0; r < COLS; ++r)
    		{
    			for (int c = 0; c < ROWS; ++c)
    			{
                    if (player.map1.getElementOnMap(r,c) == 1) // Destroyable wall
    				{
    					DrawIMG( walls, screen, c * TILE_WIDTH, r * TILE_HEIGHT);
    				}
                    if (player.map1.getElementOnMap(r,c)  == 2) // Solid wall
    				{
    					DrawIMG( solid, screen, c * TILE_WIDTH, r * TILE_HEIGHT);
    				}
    			}
    		}
        	//*******************************************************************
    		//handle bomberman movement/actions
    		    if (Keys[SDLK_LEFT] ) {
    		    	player.move(Directions::left); // move Bomberman to the left
    		    }
    		    if (Keys[SDLK_RIGHT]) {
    		    	player.move(Directions::right); // move Bomberman to the right
    		    }
    		    if (Keys[SDLK_UP] ) {
    		    	player.move(Directions::up); // move Bomberman to the up
    		    }
    		    if (Keys[SDLK_DOWN] ) {
    		    	player.move(Directions::down); // move Bomberman to the down
    		    }
    		    if (Keys[SDLK_SPACE] ) {
    		    	player.putBomb(screen, &player.map1); // press Spacebar to put a bomb!
    		    }

        	player.init(screen);
        	//*******************************************************************

    		// Flip the screen
            SDL_Flip(screen);
    	}
        printf("+++++++++ 2 +++++++++++\n");
    SDL_Quit();
}
