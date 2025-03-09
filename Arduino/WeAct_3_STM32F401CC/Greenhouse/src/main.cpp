#include <Arduino.h>

#include "Display/LED.h"
#include "Display/OLED.h"
#include "Sensors/LightSensor.h"
#include "Sensors/TempAndHumidSensor.h"
#include "Devices/ServoControl.h"

LED built_in_led = LED(LED_BUILTIN);
OLED oled = OLED();
TempAndHumidSensor temp_and_humid_sensor = TempAndHumidSensor();
LightSensor light_sensor = LightSensor();

ServoControl servo = ServoControl(PC14);

void setup()
{
  servo.Init();
  built_in_led.Init();
  oled.Init();
  temp_and_humid_sensor.Init();
  light_sensor.Init();
}

void loop()
{
  servo.SetAngle(180);
  delay(500);
  servo.SetAngle(0);
/*   TempAndHumidSensor::Data tempAndHumid_data = temp_and_humid_sensor.Get_mean_data();
  float light_data = light_sensor.Get_mean_data();

  oled.Clear();

  String text[3];
  text[0] = "Light: " + String(light_data);
  text[1] = "Temp: " + String(tempAndHumid_data.temperature);
  text[2] = "Humid: " + String(tempAndHumid_data.humidity);
  oled.Print(text, 3);

  built_in_led.blink(50, 50, 3); */

  delay(1000);
}