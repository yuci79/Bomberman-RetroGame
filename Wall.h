
#ifndef WALL_H
#define WALL_H

#include <string>
#include vector



/**
  * class Wall
  * 
  */

class Wall
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Wall ();

  /**
   * Empty Destructor
   */
  virtual ~Wall ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   */
  void destroy ()
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

  char position;
  void solid;
public:


  // Private attribute accessor methods
  //  

private:

public:


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
   * Set the value of solid
   * @param new_var the new value of solid
   */
  void setSolid (void new_var)   {
      solid = new_var;
  }

  /**
   * Get the value of solid
   * @return the value of solid
   */
  void getSolid ()   {
    return solid;
  }
private:


  void initAttributes () ;

};

#endif // WALL_H
