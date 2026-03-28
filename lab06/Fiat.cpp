#include "Weather.h"
#include "Car.h"
#include "Fiat.h"
#include <cstring>

Fiat::Fiat() {
    this->name = new char[20];
    strcpy(this->name, "Fiat");
    this->fuel_cap = 32;
    this->fuel_consumption = 42;
}
void Fiat::calculateSpeed(Weather weather) {
    switch (weather) {
        case Weather::Sunny: {
            this->avg_speed = 8;
            break;
        }
        case Weather::Rain: {
            this->avg_speed = 95;
            break;
        }
        case Weather::Snow: {
            this->avg_speed = 61;
            break;
        }
    }
}
