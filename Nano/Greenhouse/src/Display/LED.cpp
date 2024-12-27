#include <Display\LED.h>

void LED::blink(int pin, int duration, int loopCount)
{
    digitalWrite(pin, LOW);

    int stepDelay = duration / (loopCount * 2);

    for (uint8_t i = 0; i < loopCount; i++)
    {
        digitalWrite(pin, HIGH);
        delay(stepDelay);
        digitalWrite(pin, LOW);
        delay(stepDelay);
    }
}