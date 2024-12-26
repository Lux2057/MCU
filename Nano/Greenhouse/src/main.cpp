#include <Arduino.h>
#include "LED/LED.h"
#include "Sensors/TempAndHumidSensor.h"

#define PUMP_MOSFET_PIN 2
#define LED_MOSFET_PIN 3

LED led = LED();
TempAndHumidSensor tempAndHumid = TempAndHumidSensor(10, 50);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_MOSFET_PIN, OUTPUT);
  pinMode(LED_MOSFET_PIN, OUTPUT);

  digitalWrite(PUMP_MOSFET_PIN, LOW);
  digitalWrite(LED_MOSFET_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  tempAndHumid.Init();

  Serial.begin(9600);
}

void loop()
{
  TempAndHumidSensor::Data data = tempAndHumid.Get_mean_data();

  Serial.print("Temperature: ");
  Serial.print(data.temperature);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(data.humidity);
  Serial.println("% rH");
}