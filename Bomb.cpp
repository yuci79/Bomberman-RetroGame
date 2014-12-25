#include "Bomb.hpp"
#include "Player.hpp"
#include "BombTimer.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
// Constructors/Destructors
//  

Bomb::Bomb () {
	cout<<"Bomb::Bomb ()"<<endl;
}

Bomb::~Bomb () { }

//  
// Methods
//  
void Bomb::Draw(SDL_Surface *screen, SDL_Rect bmb_coordinate)
{
	/* load bomb image */
	temp   = SDL_LoadBMP("bomb.bmp");
	bomb = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	/* draw the bomb */
	SDL_BlitSurface(bomb, NULL, screen, &bmb_coordinate);
    /* update the screen */
	//this->screen = screen;
}

void Bomb::DrawExplosion(SDL_Surface *screen, SDL_Rect bmb_coordinate)
{
	/* load explosion image */
	temp_explosion   = SDL_LoadBMP("bomberman.bmp");
	explosion = SDL_DisplayFormat(temp_explosion);
	SDL_FreeSurface(temp_explosion);

	/* draw the explosion */
	SDL_BlitSurface(explosion, NULL, screen, &bmb_coordinate);
    /* update the screen */
	sleep(2);
}

// Other methods
//  
void Bomb::setPosition (int x, int y, Map *map , SDL_Surface *screen)
{
	this->x = x/TILE_WIDTH;
	this->y = y/TILE_HEIGHT;
	map->setElementOnMap(this->y, this->x, 3);

    thread t1(&Bomb::tick, this, this->x, this->y, map, screen);
    t1.detach();
	cout<<"setPosition: "<<this->x<<","<<this->y<<endl;
}

int Bomb::getX()
{
	return this->x * TILE_WIDTH;
}

void Bomb::tick(int x, int y, Map *map, SDL_Surface *screen)
{
    cout << "Bomb::tick()  x:"<< x <<" y: "<< y << endl;
    BombTimer timer(1000, 0);
    timer.start();
    int i = 1;
    while (timer.isRunning() && i != EXPLOSION_TIME)
    {
       if (timer.hasTicked())
       {
          cout << "tick tack " << i++ << endl;
       }
    }
    // bomb time is ended, now call the explosion function
    cout << "BOOM"<< endl;
    explode(x,y, map, screen);
}

void Bomb::explode(int x, int y, Map *map, SDL_Surface *screen)
{
	cout << "Bomb::explode  x:"<< x <<" y: "<< y << endl;
	int W,E,N,S; // directions
	for(int i = 0; i < range; i++)
	{
		cout<<"i= "<< i <<endl;
		if(map->getElementOnMap(y-1,x) != 2)
		{
			if(map->getElementOnMap(y-1,x) == 1)
			{
				map->DestroyWall(y-1,x);
			}
			else if(map->checkBlankSpace(y-i,x))
			{
				//DrawExplosion(screen, rcExplosion);
				cout<<"checkBlankSpace y-i= "<< y-i <<endl;
				map->DestroyWall(y-i,x);
			}
		}
		if(map->getElementOnMap(y+1,x) != 2)
		{
			if(map->getElementOnMap(y+1,x) == 1 )
			{
				map->DestroyWall(y+1,x);
			}
			else if(map->checkBlankSpace(y+i,x))
			{
				cout<<"checkBlankSpace  y+i= "<< y+i <<endl;
				map->DestroyWall(y+i,x);
			}
		}
		if(map->getElementOnMap(y,x-1) != 2)
		{
			if(map->getElementOnMap(y,x-1) == 1 )
			{
				map->DestroyWall(y,x-1);
			}
			else if(map->checkBlankSpace(y,x-i))
			{
				cout<<"checkBlankSpace x-i= "<< x-i <<endl;
				map->DestroyWall(y,x-i);
			}
		}
		if(map->getElementOnMap(y,x+1) != 2)
		{
			if(map->getElementOnMap(y,x+1) == 1)
			{
				map->DestroyWall(y,x+1);
			}
			else if(map->checkBlankSpace(y,x+i))
			{
				cout<<"checkBlankSpace x+i= "<< x+i <<endl;
				map->DestroyWall(y,x+i);
			}
		}
	}
	// set bomb place as empty space
	map->setElementOnMap(y, x, 0);
	is_bomb_dropped = false;
}

int Bomb::getY()
{
	return this->x * TILE_HEIGHT;
}
