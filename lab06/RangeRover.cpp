#include "Weather.h"
#include "Car.h"
#include "RangeRover.h"
#include <cstring>

RangeRover::RangeRover() {
    this->name = new char[20];
    strcpy(this->name, "RangeRover");
    this->fuel_cap = 90;
    this->fuel_consumption = 12;
}
void RangeRover::calculateSpeed(Weather weather) {
    switch (weather) {
        case Weather::Sunny: {
            this->avg_speed = 66;
            break;
        }
        case Weather::Rain: {
            this->avg_speed = 33;
            break;
        }
        case Weather::Snow: {
            this->avg_speed = 41;
            break;
        }
    }
}
