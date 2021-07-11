/*
  SimpleDelay.h - Library for a non blocking, event driven delay library
  Created by Thomas Pike, July 11, 2021.
*/

#ifndef SimpleDelay_h
#define SimpleDelay_h

class SimpleDelay
{
  public:

    bool isRunning;
    int delayMillis;

    typedef void (*callbackFunction)();

    callbackFunction updateFunction;
    callbackFunction startFunction;
    callbackFunction endFunction;

    unsigned long startMillis;
    unsigned long currentMillis;
    unsigned long endMillis;

    void start(unsigned long millis);
    void end();
    void tick(unsigned long millis);

    SimpleDelay(int delayMillis_Set, callbackFunction startFunc, callbackFunction updateFunc, callbackFunction endFunc);
};

#endif