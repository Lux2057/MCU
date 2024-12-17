#include <Arduino.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink(int duration, int interval, int loopCount)
{
  digitalWrite(LED_BUILTIN, LOW);
  for (int i = 0; i < loopCount; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(duration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(interval);
  }
}

void loop()
{
  blink(300, 100, 5);
  delay(1000);
}