#include <Arduino.h>
#include "LED/LED.h"
#include "Sensors/AHT10/AHT10.h"

#define PUMP_MOSFET_PIN 2
#define LED_MOSFET_PIN 3

LED led = LED();
AHT10 aht10 = AHT10(10, 50);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_MOSFET_PIN, OUTPUT);
  pinMode(LED_MOSFET_PIN, OUTPUT);

  digitalWrite(PUMP_MOSFET_PIN, LOW);
  digitalWrite(LED_MOSFET_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  aht10.Init();

  Serial.begin(9600);
}

void loop()
{
  AHT10::Data data = aht10.Get_mean_data();

  Serial.print("Temperature: ");
  Serial.print(data.temperature);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(data.humidity);
  Serial.println("% rH");
}