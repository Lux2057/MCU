#include <Arduino.h>

#define PUMP_MOSFET_PIN 2
#define LED_MOSFET_PIN 3

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_MOSFET_PIN, OUTPUT);
  pinMode(LED_MOSFET_PIN, OUTPUT);

  digitalWrite(PUMP_MOSFET_PIN, LOW);
  digitalWrite(LED_MOSFET_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void blink(int duration, int interval, int loopCount)
{
  digitalWrite(LED_BUILTIN, LOW);
  
  int stepDuration = duration / loopCount;

  for (int i = 0; i < loopCount; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(stepDuration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(interval);
  }
}

void loop()
{
  digitalWrite(PUMP_MOSFET_PIN, HIGH);
  blink(5000, 100, 10);
  digitalWrite(PUMP_MOSFET_PIN, LOW);

  delay(2000);

  digitalWrite(LED_MOSFET_PIN, HIGH);
  blink(5000, 100, 30);
  digitalWrite(LED_MOSFET_PIN, LOW);

  delay(1000);
}