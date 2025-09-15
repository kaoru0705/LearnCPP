#include "Car.h"
#include <iostream>

Car::Car(const std::string& name, int speed) : name{ name }, speed{ speed } {}

void Car::drive() {
    std::cout << name << " is driving at " << speed << " km/h." << std::endl;
}

void Car::stop() {
    std::cout << name << " has stopped." << std::endl;
}
