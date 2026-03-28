#pragma once

#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    int length;
    Weather weather;
    Car **cars;
    int times[10];
    int car_count;
public:
    Circuit();
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car *car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
