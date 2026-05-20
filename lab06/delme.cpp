#include <iostream>
#include <cstring>
using namespace std;

enum class Weather {
    Rain,
    Sunny,
    Snow,
};

class Car {
public:
    char *name;
    int fuel_cap;
    int fuel_consumption;
    int avg_speed;
    virtual void calculateSpeed(Weather weather) = 0;
};

class Volvo : public Car {
public:
    Volvo();
    void calculateSpeed(Weather weather) override;
};
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

class BMW : public Car {
public:
    BMW();
    void calculateSpeed(Weather weather) override;
};
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

class Seat : public Car {
public:
    Seat();
    void calculateSpeed(Weather weather) override;
};
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

class Fiat : public Car {
public:
    Fiat();
    void calculateSpeed(Weather weather) override;
};
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

class RangeRover : public Car {
public:
    RangeRover();
    void calculateSpeed(Weather weather) override;
};
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

int main()
{
   Circuit c;
   c.SetLength(100);
   c.SetWeather(Weather::Rain);
   c.AddCar(new Volvo());
   c.AddCar(new BMW());
   c.AddCar(new Seat());
   c.AddCar(new Fiat());
   c.AddCar(new RangeRover());
   c.Race();
   c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
   c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
   return 0;
}
