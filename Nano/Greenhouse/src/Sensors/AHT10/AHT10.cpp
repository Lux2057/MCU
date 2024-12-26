#include "Sensors/AHT10/AHT10.h"

AHT10::AHT10(int measurementCount = 10, int measurementDelay = 500)
{
    this->measurementCount = measurementCount;
    this->measurementDelay = measurementDelay;
}

void AHT10::Init()
{
    this->aht.begin();
}

AHT10::Data AHT10::Get_mean_data()
{
    float mean_temperature = 0.0;
    float mean_humidity = 0.0;

    for (int i = 0; i < this->measurementCount; i++)
    {
        sensors_event_t humidity, temp;
        aht.getEvent(&humidity, &temp);

        mean_humidity += humidity.relative_humidity;
        mean_temperature += temp.temperature;

        delay(this->measurementDelay);
    }

    Data result = Data();
    result.humidity = mean_humidity / this->measurementCount;
    result.temperature = mean_temperature / this->measurementCount;

    return result;
}