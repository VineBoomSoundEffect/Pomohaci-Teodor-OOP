#pragma once

#include "Weather.h"

class Car {
public:
    char *name;
    int fuel_cap;
    int fuel_consumption;
    int avg_speed;
    virtual void calculateSpeed(Weather weather) = 0;
};
