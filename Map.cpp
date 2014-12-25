#include "Map.h"
#include <math.h>
#include <iostream>
using namespace std;

// Constructors/Destructors
//  

Map::Map () {
	// Copy const map to another dynamic 2D array
	for (int i = 0; i<COLS; i++)
	  {
		for (int j = 0; j < ROWS; j++)
		{
			dynamic_map[i][j] = map[i][j];
		}
	  }
}

Map::~Map () { }

bool Map::isWallExist (int x_coordinate, int y_coordinate, int direction)
{
    x =  ceil(x_coordinate/TILE_WIDTH);
    y =  ceil(y_coordinate/TILE_HEIGHT);
    cout<<"x: "<< x <<"  y: "<< y <<"  direction: "<< direction <<endl ;
    cout<<"map(x):  map(y): "<< dynamic_map[y][x] <<endl ;
    cout<<"map[y][x-1]: "<< dynamic_map[y][x-1] <<endl ;
    cout<<"map[y][x+1]: "<< dynamic_map[y][x+1] <<endl ;
    cout<<"map[y-1][x]: "<< dynamic_map[y-1][x] <<endl ;
    cout<<"map[y+1][x]: "<< dynamic_map[y+1][x] <<endl ;
    switch(direction){
    	case Directions::right:
    		if(dynamic_map[y][x+1] > 0 && x_coordinate%TILE_WIDTH == 0) return true;
    	break;
    	case Directions::left:
    		if(dynamic_map[y][x-1] > 0 && x_coordinate%TILE_WIDTH == 0) return true;
    	break;
    	case Directions::up:
    		if(dynamic_map[y-1][x] > 0  && y_coordinate%TILE_WIDTH == 0) return true;
    	break;
    	case Directions::down:
    		if(dynamic_map[y+1][x] > 0  && y_coordinate%TILE_WIDTH == 0 ) return true;
    	break;
    }
    return false;
}

void Map::DestroyWall (int column, int row)
{
	setElementOnMap(column, row, 0);
}

int Map::getElementOnMap (int col, int row)
{
	return dynamic_map[col][row];
}

void Map::setElementOnMap (int col, int row, int value)
{
	dynamic_map[col][row] = value;
}
bool Map::checkBlankSpace(int x, int y)
{
    bool value = false;
    if(dynamic_map[x][y] == 0)
    {
    	value = true;
    }
    return value;
}

int Map::getX ()
{}
