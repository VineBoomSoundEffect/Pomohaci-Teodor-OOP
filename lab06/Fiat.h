#pragma once

#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    void calculateSpeed(Weather weather) override;
};
