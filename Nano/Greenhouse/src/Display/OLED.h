#ifndef OLED_H
#define OLED_H

#include <Arduino.h>

class OLED
{
public:
    struct Point
    {
        int X;
        int Y;
    };

    void Print(Point start, int lineHeight, String lines[], int linesCount);
    void Init();
};

#endif