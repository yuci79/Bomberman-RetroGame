#include "Player.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;
// Constructors/Destructors
//  

Player::Player (Game *g)
{
	screen = g->screen;
	init(screen);	//bomb.init(screen);
    rcBmb.x = 32;
    rcBmb.y = 32;
}

Player::~Player () { }

void Player::init (SDL_Surface *screen) {

	/* load Bomberman image */
	temp   = SDL_LoadBMP("bomberman.bmp");
	bomberman = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	/* draw the bomberman */
	SDL_BlitSurface(bomberman, NULL, screen, &rcBmb);
    /* update the screen */
    SDL_UpdateRect(screen, 0, 0, 0, 0);

    //Check that if any bomb is dropped by player. If true display the bomb.
	if(bomb.is_bomb_dropped && getPlayerBombCount())
	{
		SDL_Rect bmb_coordinate;
		bmb_coordinate.x = TILE_WIDTH * bomb.x;
		bmb_coordinate.y = TILE_HEIGHT * bomb.y;
		bomb.Draw(screen, bmb_coordinate);
	}
}

void Player::move(int direction)
{
    cout<< "move it"<<endl;
	if(direction == Directions::left && !getAnyWallExist(direction))
	{
		rcBmb.x -= 1;
        cout<< "left"<<endl;
	}
	if(direction == Directions::right && !getAnyWallExist(direction))
	{
		rcBmb.x += 1;
        cout<< "right"<<endl;
	}
	if(direction == Directions::up && !getAnyWallExist(direction))
	{
		rcBmb.y -= 1;
	}
	if(direction == Directions::down && !getAnyWallExist(direction))
	{
		rcBmb.y += 1;
	}
}

void Player::putBomb(SDL_Surface *screen, Map *map)
{
	if(bomb.is_bomb_dropped == false)
	{
		cout<<"Player::putBomb"<<endl;
		bomb.setPosition(rcBmb.x, rcBmb.y, map, screen);
		cout<<"Draw"<<endl;
		bomb.Draw(screen, rcBmb);
		//map1.DestroyWall(2,4);
		bomb.is_bomb_dropped = true;
		cout<<"Bomb coordinate: "<<rcBmb.x<<","<<rcBmb.y<<endl;
	}
}

int Player::getAnyWallExist(int direction)
{
	bool result = false;
	 cout<<"current coordinate: "<<rcBmb.x<<","<<rcBmb.y<<endl;
	 if(map1.isWallExist(rcBmb.x, rcBmb.y, direction))
	 {
		 cout<<"result=true"<<endl;
		 result = true;
	 }

	 return result;
}
