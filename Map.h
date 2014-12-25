#ifndef MAP_H
#define MAP_H

#include <string>

// For the map
const int ROWS = 30;
const int COLS = 20;
namespace Directions {
 enum {
	left = 0,
	right,
	up,
	down
} ;
}
// tile size
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
// Set  destroyable and solid walls location on map
// Empt space        = 0;
// Destroyable walls = 1;
// Solid walls       = 2;
// Bomb              = 3;
const int map [COLS][ROWS] =
			{
					{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
					{2,0,1,0,1,1,0,1,0,2,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,0,0,0,1,1,0,1,0,2,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2},
					{2,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,2},
					{2,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,0,1,0,2},
					{2,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,1,1,1,2},
					{2,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,2},
					{2,0,1,0,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,2,0,0,0,1,1,0,1,0,2},
					{2,0,1,0,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,2,0,0,0,1,1,0,1,0,2},
					{2,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,1,2,0,0,0,1,2,2,2,2,2},
					{2,0,0,0,0,1,0,1,0,2,1,0,1,0,1,1,0,1,0,1,2,0,1,0,1,1,0,0,0,2},
					{2,0,1,0,0,1,0,1,0,2,1,0,1,0,1,0,0,1,0,1,2,0,1,0,1,1,0,1,0,2},
					{2,0,1,0,1,1,0,0,0,2,1,0,1,0,1,0,0,1,0,1,2,0,1,0,1,0,0,1,0,2},
					{2,0,1,0,1,1,0,1,0,2,1,0,1,0,1,0,0,1,0,1,2,0,1,0,1,0,0,1,0,2},
					{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
			};


/**
  * class Map
  * 
  */

class Map
{
private:

	  int x;
	  int y;
	  int dynamic_map[COLS][ROWS];

public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Map ();

  /**
   * Empty Destructor
   */
  virtual ~Map ();


  /**
   */
  void GetY ()
  {
  }

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of x
   * @param new_var the new value of x
   */
  void setX (int new_var)   {
      x = new_var;
  }

  /**
   * Get the value of x
   * @return the value of x
   */
  int getX ();

  /**
   * Set the value of y
   * @param new_var the new value of y
   */
  void setY (int new_var)   {
      y = new_var;
  }

  /**
   * Get the value of y
   * @return the value of y
   */
  int getY ()   {
    return y;
  }

  /**
   * Get specific element of column and row
   * @return the value
   */
  int getElementOnMap (int col, int row);

  /**
   * Set specific element of column and row
   * @param col,row,value
   */
  void setElementOnMap (int col, int row, int value);

  /**
   * Destroy wall
   * @param column and row
   */
  virtual bool isWallExist (int x, int y, int direction);

  /**
   * Destroy wall
   * @param column and row
   */
  void DestroyWall (int column, int row);

  /**
   * Get blank space
   * @return the value
   */
  bool checkBlankSpace(int x, int y);

private:


  void initAttributes () ;

};

#endif // MAP_H
