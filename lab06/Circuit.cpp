#include "Circuit.h"
#include "Car.h"
#include <stdlib.h>
#include <iostream>

Circuit::Circuit() {
    for (int i = 0; i < 10; i++) {
        times[i] = 0;
    }
    this->car_count = 0;
    this->cars = (Car **)malloc(10 * sizeof(Car *));
}
void Circuit::SetLength(int length) {
    this->length = length;
}
void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}
void Circuit::AddCar(Car *car) {
    cars[car_count] = car;
    cars[car_count]->calculateSpeed(this->weather);
    car_count++;
}
void Circuit::Race() {
    int distance;
    for (int i = 0; i < car_count; i++) {
        distance = 0;
        while(cars[i]->fuel_cap >= 0 && distance < this->length) {
            cars[i]->fuel_cap -= cars[i]->fuel_consumption;
            times[i]++;
            distance += cars[i]->avg_speed;
        }
        if (distance < this->length) {
            times[i] = 1000000;
        }
    }
}
void Circuit::ShowFinalRanks() {
    int aux;
    Car *auxCar;
    for (int i = 0; i < this->car_count-1; i++) {
        for (int j = i; j < this->car_count; j++) {
            if (this->times[i] > this->times[j]) {
                aux = this->times[i];
                this->times[i] = this->times[j];
                this->times[j] = aux;

                auxCar = this->cars[i];
                this->cars[i] = this->cars[j];
                this->cars[j] = auxCar;
            }
        }
    }
    for (int i = 0; i < this->car_count; i++) {
        std::cout << this->cars[i]->name << ": ";
        if (this->times[i] == 1000000) std::cout << "infinity" << "\n";
        else std::cout << this->times[i] << "\n";
    }
}
void Circuit::ShowWhoDidNotFinish() {
    std::cout << "Cars who did not finish:\n";
    for (int i = 0; i < this->car_count; i++) {
        if (times[i] == 1000000) std::cout << "  - " << this->cars[i]->name << "\n";
    }
}
