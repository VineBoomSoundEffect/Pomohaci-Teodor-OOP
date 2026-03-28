#include "Weather.h"
#include "Car.h"
#include "BMW.h"
#include <cstring>

BMW::BMW() {
    this->name = new char[20];
    strcpy(this->name, "BMW");
    this->fuel_cap = 30;
    this->fuel_consumption = 100;
}
void BMW::calculateSpeed(Weather weather) {
    switch (weather) {
        case Weather::Sunny: {
            this->avg_speed = 5;
            break;
        }
        case Weather::Rain: {
            this->avg_speed = 2;
            break;
        }
        case Weather::Snow: {
            this->avg_speed = 78;
            break;
        }
    }
}
