#include <Arduino.h>
#include "LED/LED.h"
#include "Sensors/TempAndHumidSensor.h"
#include "Sensors/LightSensor.h"

#define PUMP_MOSFET_PIN 2
#define LED_MOSFET_PIN 3

LED led = LED();
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

  tempAndHumid.Init();
  lightSensor.Init();

  Serial.begin(9600);
}

void loop()
{
  TempAndHumidSensor::Data tempAndHumid_data = tempAndHumid.Get_mean_data();

  led.blink(LED_BUILTIN, 500, 2);

  float light_data = lightSensor.Get_mean_data();

  led.blink(LED_BUILTIN, 500, 5);

  Serial.print("Ambient: ");
  Serial.println(light_data);

  Serial.print("Temperature: ");
  Serial.print(tempAndHumid_data.temperature);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(tempAndHumid_data.humidity);
  Serial.println("% rH");
}