#ifndef PLAYER_H
#define PLAYER_H
#include "Character.hpp"
#include "Game.hpp"
#include "Bomb.hpp"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

/**
  * class Player
  * 
  */

class Player: public Character
{
private:
  // Private attributes
  //

  char position;
  int hearts;
  int speed;
  long score;
  int player_current_bomb_count;
  SDL_Surface *temp, *bomberman;
  SDL_Rect rcBmb;
  SDL_Surface *screen;
  //Player(const Player& p) { screen = p.screen; }   // copy constructor

  // Constructors/Destructors
  //  
public:
  Map map1;
  Bomb bomb;

SDL_Surface * getScreen() {return this->screen;}

void setScreen(SDL_Surface* scr) {screen = scr;}
  /**
   * Empty Constructor
   */
  Player () {}

  Player (Game *g) ;
  /**
   * Empty Destructor
   */
  virtual ~Player ();

  // Static Public attributes
  //  

  void init (SDL_Surface *screen) ;
  /**
   */
  void move(int direction);


  /**
   */
  void putBomb (SDL_Surface *screen, Map *map);

  /**
   */
  int getAnyWallExist(int direction);

  /**
   */
  void addScore ()
  {
  }


  /**
   */
  void die ()
  {
  }


  /**
   */
  void addHerts ()
  {
  }


  /**
   */
  void addSpeed ()
  {
  }

public:

  /**
   * Set the value of position
   * @param new_var the new value of position
   */
  void setPosition (char new_var)   {
      position = new_var;
  }

  /**
   * Get the value of position
   * @return the value of position
   */
  char getPosition ()   {
    return position;
  }

  /**
   * Set the value of hearts
   * @param new_var the new value of hearts
   */
  void setHearts (int new_var)   {
      hearts = new_var;
  }

  /**
   * Get the value of hearts
   * @return the value of hearts
   */
  int getHearts ()   {
    return hearts;
  }

  /**
   * Set the value of speed
   * @param new_var the new value of speed
   */
  void setSpeed (int new_var)   {
      speed = new_var;
  }

  /**
   * Get the value of speed
   * @return the value of speed
   */
  int getSpeed ()   {
    return speed;
  }

  /**
   * Set the value of score
   * @param new_var the new value of score
   */
  void setScore (long new_var)   {
      score = new_var;
  }

  /**
   * Get the value of score
   * @return the value of score
   */
  long getScore ()   {
    return score;
  }

  /**
   * Get the count of player bomb(s)
   * @return the value of bomb(s)
   */
  int getPlayerBombCount ()   {
    return player_current_bomb_count;
  }

  /**
   * Set the current count of bombs
   * @param bombs the new value of bombs
   */
  void setPlayerBombCount (int bombs)   {
	  player_current_bomb_count = bombs;
  }


};

#endif // PLAYER_H
