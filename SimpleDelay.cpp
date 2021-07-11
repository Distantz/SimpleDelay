/*
  SimpleDelay.cpp - Library for a non blocking, event driven delay library
  Created by Thomas Pike, July 11, 2021.
*/

#include "SimpleDelay.h"

// Simple Delay

void SimpleDelay::start(unsigned long millis)
{

  if (startFunction && !isRunning)
  {
    startFunction();
  }

  isRunning = true;
  startMillis = millis;
  endMillis = startMillis + delayMillis;
}

void SimpleDelay::end()
{
  isRunning = false;
  currentMillis = 0;
  endMillis = 0;
  startMillis = 0;
}

void SimpleDelay::tick(unsigned long millis)
{

  if (isRunning)
  {

    currentMillis = millis;

    if (currentMillis >= endMillis) // Check if is end cycle
    {
      if (endFunction)
      {
        endFunction();
      }

      end();

    }
    else // Else do update cycle
    {

      if (updateFunction)
      {
        updateFunction();
      }

    }
  }
}

SimpleDelay::SimpleDelay(int delayMillis_Set, SimpleDelay::callbackFunction startFunc, SimpleDelay::callbackFunction updateFunc, SimpleDelay::callbackFunction endFunc)
{

  delayMillis = delayMillis_Set;
  
  startFunction = startFunc;
  updateFunction = updateFunc;
  endFunction = endFunc;

  isRunning = false;

}