#include <Arduino.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); 
}

void blink(int litDuration, int litInterval, int loopCount)
{
  digitalWrite(LED_BUILTIN, LOW);

  for (int i = 0; i < loopCount; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(litDuration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(litInterval);
  }

  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  blink(200, 100, 4);
  delay(1000);
}