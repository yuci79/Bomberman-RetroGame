
#ifndef BOMB_H
#define BOMB_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Map.h"
//#include "Player.hpp"


/**
  * class Bomb
  * 
  */

class Bomb
{

private:
	  int type;
	  int range = 3; // Destroy by 3 walls vertical and diagonal
	  SDL_Surface *temp, *bomb, *explosion, *temp_explosion;
	  SDL_Surface *screen;
	  SDL_Rect rcExplosion;

public:
	  int x,y;
      bool is_bomb_dropped = false;

  // Constructors/Destructors
  //  

  /**
   * Empty Constructor
   */
  Bomb ();

  /**
   * Empty Destructor
   */
  virtual ~Bomb ();


  void Draw(SDL_Surface *screen, SDL_Rect bmb_coordinate);

  void DrawExplosion(SDL_Surface *screen, SDL_Rect bmb_coordinate);

  /**
   */
  void tick (int x, int y, Map *map, SDL_Surface *screen);


  /**
   */
  void explode (int x, int y, Map *map, SDL_Surface *screen);

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of position
   * @param new_var the new value of position
   */
  void setPosition (int x, int y, Map *map, SDL_Surface *screen);

  /**
   * Get the value of position
   * @return the value of position
   */
  void getPosition () ;

  /**
   * Set the value of type
   * @param new_var the new value of type
   */
  void setType (int new_var) ;

  /**
   * Get the value of type
   * @return the value of type
   */
  void getType ()  ;
  /**
   * Set the value of range
   * @param new_var the new value of range
   */
  void setExplosionRange (int new_var) ;


  /**
   * Get the value of range
   * @return the value of range
   */
  void getExplosionRange () ;

  /**
   * Get bomb x coordinate
   * @return the value of x
   */
  int getX();

  int getY();
private:


  void initAttributes () ;

};

#endif // BOMB_H
