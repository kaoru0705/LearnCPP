#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    Car(const std::string& name, int speed);
    void drive();
    void stop();

private:
    std::string name;
    int speed;
};

#endif
