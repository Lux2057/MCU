#include <Arduino.h>
#include "Display/LED.h"
#include "Display/OLED.h"
#include "Sensors/LightSensor.h"
#include "Sensors/TempAndHumidSensor.h"
#include <Servo.h>

LED built_in_led = LED(LED_BUILTIN);
OLED oled = OLED();
TempAndHumidSensor temp_and_humid_sensor = TempAndHumidSensor();
LightSensor light_sensor = LightSensor();

Servo servo;
int servo_pin = PC14;

void setup()
{
  servo.attach(servo_pin);
  servo.write(5);
  delay(50);  

  built_in_led.Init();
  oled.Init();
  temp_and_humid_sensor.Init();
  light_sensor.Init();
}

void loop()
{
  TempAndHumidSensor::Data tempAndHumid_data = temp_and_humid_sensor.Get_mean_data();
  float light_data = light_sensor.Get_mean_data();

  oled.Clear();

  String text[3];
  text[0] = "Light: " + String(light_data);
  text[1] = "Temp: " + String(tempAndHumid_data.temperature);
  text[2] = "Humid: " + String(tempAndHumid_data.humidity);
  oled.Print(text, 3);

  built_in_led.blink(50, 50, 3);

  delay(1000);
}