
#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"

#include <string>

/**
  * class Monster
  * 
  */

/******************************* Abstract Class ****************************
Monster does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Monster : public Character
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Monster ();

  /**
   * Empty Destructor
   */
  virtual ~Monster ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


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

  int hearts;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


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
private:


  void initAttributes () ;

};

#endif // MONSTER_H
