#include <Arduino.h>
#include "Display/LED.h"
#include "Display/OLED.h"
#include "Sensors/TempAndHumidSensor.h"
#include "Sensors/LightSensor.h"

#define PUMP_MOSFET_PIN 2
#define LIGHT_MOSFET_PIN 3

LED led = LED();
OLED oled = OLED();
TempAndHumidSensor tempAndHumid = TempAndHumidSensor(10, 50);
LightSensor lightSensor = LightSensor(10, 50);

bool PumpIsActive = false;
bool LightIsActive = false;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_MOSFET_PIN, OUTPUT);
  pinMode(LIGHT_MOSFET_PIN, OUTPUT);

  digitalWrite(PUMP_MOSFET_PIN, LOW);
  digitalWrite(LIGHT_MOSFET_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  oled.Init();
  tempAndHumid.Init();
  lightSensor.Init();
}

void loop()
{
  TempAndHumidSensor::Data tempAndHumid_data = tempAndHumid.Get_mean_data();
  float light_data = lightSensor.Get_mean_data();

  if (PumpIsActive)
  {
    if (light_data < 120)
    {
      digitalWrite(PUMP_MOSFET_PIN, LOW);
      PumpIsActive = false;
    }
  }
  else
  {
    if (light_data > 100)
    {
      digitalWrite(PUMP_MOSFET_PIN, HIGH);
      PumpIsActive = true;
    }
  }

  oled.Clear();

  String text[3];
  text[0] = "Light: " + String(light_data);
  text[1] = "Temp: " + String(tempAndHumid_data.temperature);
  text[2] = "Humid: " + String(tempAndHumid_data.humidity);
  oled.Print(text, 3);
}