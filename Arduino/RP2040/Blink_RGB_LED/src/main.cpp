#include <FastLED.h>

#define LED_PIN 16
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 1

#define BRIGHTNESS 20

CRGB leds[NUM_LEDS];

void light()
{
  leds[0] = CRGB::White;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Black;
  FastLED.show();
}

void setup()
{
  delay(3000);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  light();  
  FastLED.delay(1000);
}