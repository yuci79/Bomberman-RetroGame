/*
 * main.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: yucel umit
 */

#include "Game.hpp"
#include <iostream>
using namespace std;

int main()
{
	Game game;
	game.init();
	game.gameLoop();

    cout<<"Game Over"<<endl;
	return 0;
}

