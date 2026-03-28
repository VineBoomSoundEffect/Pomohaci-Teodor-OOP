#pragma once

#include "Car.h"

class BMW : public Car {
public:
    BMW();
    void calculateSpeed(Weather weather) override;
};
