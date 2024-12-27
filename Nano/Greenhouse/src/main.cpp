#include <Arduino.h>
#include "Display/LED.h"
#include "Display/OLED.h"
#include "Sensors/TempAndHumidSensor.h"
#include "Sensors/LightSensor.h"

#define PUMP_MOSFET_PIN 2
#define LED_MOSFET_PIN 3

LED led = LED();
OLED oled = OLED();
TempAndHumidSensor tempAndHumid = TempAndHumidSensor(10, 50);
LightSensor lightSensor = LightSensor(10, 50);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_MOSFET_PIN, OUTPUT);
  pinMode(LED_MOSFET_PIN, OUTPUT);

  digitalWrite(PUMP_MOSFET_PIN, LOW);
  digitalWrite(LED_MOSFET_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  oled.Init();
  tempAndHumid.Init();
  lightSensor.Init();  
}

void loop()
{
  TempAndHumidSensor::Data tempAndHumid_data = tempAndHumid.Get_mean_data();

  led.blink(LED_BUILTIN, 500, 1);

  float light_data = lightSensor.Get_mean_data();

  led.blink(LED_BUILTIN, 500, 2);

  oled.Clear();  

  String text[3];
  text[0] = "Light: " + String(light_data);
  text[1] = "Temp: " + String(tempAndHumid_data.temperature);
  text[2] = "Humid: " + String(tempAndHumid_data.humidity);
  oled.Print(text, 3);
}