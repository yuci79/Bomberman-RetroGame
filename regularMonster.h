
#ifndef REGULARMONSTER_H
#define REGULARMONSTER_H
#include "Monster.h"

#include <string>
#include vector



/**
  * class regularMonster
  * 
  */

class regularMonster : virtual public Monster
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  regularMonster ();

  /**
   * Empty Destructor
   */
  virtual ~regularMonster ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @param  hearts
   * @param  graphics
   */
   regularMonster (int hearts, Image graphics)
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  int speed;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


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
private:


  void initAttributes () ;

};

#endif // REGULARMONSTER_H
