#include "Weather.h"
#include "Car.h"
#include "Seat.h"
#include <cstring>

Seat::Seat() {
    this->name = new char[20];
    strcpy(this->name, "Seat");
    this->fuel_cap = 73;
    this->fuel_consumption = 51;
}
void Seat::calculateSpeed(Weather weather) {
    switch (weather) {
        case Weather::Sunny: {
            this->avg_speed = 95;
            break;
        }
        case Weather::Rain: {
            this->avg_speed = 82;
            break;
        }
        case Weather::Snow: {
            this->avg_speed = 5;
            break;
        }
    }
}
