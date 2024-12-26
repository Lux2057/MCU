#ifndef AHT10_H
#define AHT10_H

#include <Arduino.h>
#include <Adafruit_AHTX0.h>

class TempAndHumidSensor
{
private:
    Adafruit_AHTX0 aht;
    int measurementCount;
    int measurementDelay;

public:
    TempAndHumidSensor(int measurementCount = 10, int measurementDelay = 500);

    struct Data
    {
        float humidity;
        float temperature;
    };

    Data Get_mean_data();
    void Init();
};

#endif