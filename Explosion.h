
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <string>
#include vector



/**
  * class Explosion
  * 
  */

class Explosion
{
public:

  // Constructors/Destructors
  //  
  int x,y;

  /**
   * Empty Constructor
   */
  Explosion ();

  /**
   * Empty Destructor
   */
  virtual ~Explosion ();

  Explosion (x,y);

  /**
   */
  void fire ()
  {
  }

protected:

  // Static Protected attributes
  //  




  // Private attribute accessor methods
  //  


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
   * Set the value of element
   * @param new_var the new value of element
   */
  void setElement (void new_var)   {
      element = new_var;
  }

  /**
   * Get the value of element
   * @return the value of element
   */
  void getElement ()   {
    return element;
  }
private:


  void initAttributes () ;

};

#endif // EXPLOSION_H
