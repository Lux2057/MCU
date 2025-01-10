#ifndef LED_H
#define LES_H

#include <Arduino.h>

class LED
{
public:
    void blink(int pin, int duration, int loopCount);
};

#endif