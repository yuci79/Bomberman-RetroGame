
#ifndef INTELLIGENTMONSTER_H
#define INTELLIGENTMONSTER_H
#include "Monster.h"

#include <string>
#include vector



/**
  * class intelligentMonster
  * 
  */

class intelligentMonster : virtual public Monster
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  intelligentMonster ();

  /**
   * Empty Destructor
   */
  virtual ~intelligentMonster ();

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
   intelligentMonster (int hearts, Image graphics)
  {
  }


  /**
   */
  void GetAwayFromBombs ()
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

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  

private:



};

#endif // INTELLIGENTMONSTER_H
