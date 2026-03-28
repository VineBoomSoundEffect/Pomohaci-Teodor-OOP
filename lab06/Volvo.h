#pragma once

#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    void calculateSpeed(Weather weather) override;
};
