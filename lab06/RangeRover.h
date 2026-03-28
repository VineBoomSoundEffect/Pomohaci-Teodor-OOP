#pragma once

#include "Car.h"

class RangeRover : public Car {
public:
    RangeRover();
    void calculateSpeed(Weather weather) override;
};
