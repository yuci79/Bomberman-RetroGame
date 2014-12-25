/*
 * BombTimer.cpp
 *
 *  Created on: Dec 23, 2014
 *      Author: yuci
 */
#include <time.h>
#include <sys/time.h>

using namespace std;

int EXPLOSION_TIME = 4;

class BombTimer
{
private:
   bool m_isRunning;
   int m_startTime;
   int m_delayAmount;
   double m_initialDelay;

public:
   BombTimer(int delayAmount, double initialDelay = 0.0)
   {
      m_delayAmount = delayAmount * 1000;
      m_initialDelay = initialDelay/1000;
   }

   void start()
   {
      m_startTime = getMilliseconds();
      clock_t endwait = clock() + m_initialDelay * CLOCKS_PER_SEC;
      while (clock() < endwait);
      m_isRunning = true;
   }

   bool isRunning()
   {
      return m_isRunning;
   }

   bool hasTicked()
   {
      if (getMilliseconds() - m_startTime > m_delayAmount)
      {
         m_startTime = getMilliseconds();
         return true;
      }
      else
      {
         return false;
      }

   }

   int getMilliseconds() const
   {
      timeval t;
      gettimeofday(&t, NULL);
      return (t.tv_sec * 1000000) + t.tv_usec;
   }
};

/*int main (int argc, char * const argv[])
{
	BombTimer timer(1000, 0);
   timer.start();
   int i = 1;
   while (timer.isRunning() && i != EXPLOSION_TIME)
   {
      if (timer.hasTicked())
      {
         cout << "tick tack " << i++ << endl;
      }
   }
}*/


