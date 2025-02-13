#include <Arduino.h>
#include "Display/LED.h"
#include "Display/OLED.h"

LED built_in_led = LED(LED_BUILTIN);
OLED oled = OLED();

void setup()
{
  built_in_led.Init();
  oled.Init();
}

void loop()
{
  built_in_led.blink(200, 100, 5);
  delay(1000);

  oled.Clear();
  String text[1];
  text[0] = "Hello, world!";
  oled.Print(text, 1);
}