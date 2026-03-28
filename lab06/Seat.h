#pragma once

#include "Car.h"

class Seat : public Car {
public:
    Seat();
    void calculateSpeed(Weather weather) override;
};
