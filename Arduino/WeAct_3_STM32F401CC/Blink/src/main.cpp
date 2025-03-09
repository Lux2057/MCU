#include <Arduino.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); 
}

void blink(int litDuration, int litInterval, int loopCount)
{
  digitalWrite(LED_BUILTIN, HIGH);

  for (int i = 0; i < loopCount; i++)
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(litDuration);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(litInterval);
  }

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
  blink(150, 50, 2);
  delay(1000);
}