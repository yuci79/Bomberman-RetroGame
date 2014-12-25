#ifndef GAME_H
#define GAME_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Map.h"

#include <string>


/**
  * class Game
  * 
  */

class Game
{
public:

  SDL_Surface *screen;
  SDL_Event event;
  //Map map;
  // Constructors/Destructors

  /**
   * Empty Constructor
   */
  Game ();

  /**
   * Empty Destructor
   */
  virtual ~Game ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  

  /**
   * Initialization method
   */
  bool init ();


  /**
   */
  void startGame ()
  {
  }


  /**
   */
  void exitGame ()
  {
  }


  /**
   */
  void goNextLevel ()
  {
  }


  /**
   */
  void gameLoop ();


  /**
   */
  void keyEvent ()
  {
  }

  void DrawIMG(SDL_Surface *img, SDL_Surface *screen, int x, int y);



private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  int level;
  int difficulty;
public:


  // Private attribute accessor methods
  //  

private:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of level
   * @param new_var the new value of level
   */
  void setLevel (int new_var)   {
      level = new_var;
  }

  /**
   * Get the value of level
   * @return the value of level
   */
  int getLevel ()   {
    return level;
  }

  /**
   * Set the value of difficulty
   * @param new_var the new value of difficulty
   */
  void setDifficulty (int new_var)   {
      difficulty = new_var;
  }

  /**
   * Get the value of difficulty
   * @return the value of difficulty
   */
  int getDifficulty ()   {
    return difficulty;
  }
private:


  void initAttributes () ;

};

#endif // GAME_H
