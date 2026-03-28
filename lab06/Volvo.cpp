#include "Weather.h"
#include "Car.h"
#include "Volvo.h"
#include <cstring>

Volvo::Volvo() {
    this->name = new char[20];
    strcpy(this->name, "Volvo");
    this->fuel_cap = 50;
    this->fuel_consumption = 10;
}
void Volvo::calculateSpeed(Weather weather) {
    switch (weather) {
        case Weather::Sunny: {
            this->avg_speed = 10;
            break;
        }
        case Weather::Rain: {
            this->avg_speed = 30;
            break;
        }
        case Weather::Snow: {
            this->avg_speed = 50;
            break;
        }
    }
}
