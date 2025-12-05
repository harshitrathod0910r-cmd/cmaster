#include <iostream>
using namespace std;

class Vehicle {
private:
    string model;
    int speed;

public:
    void setData(string m, int s) {
        model = m;
        speed = s;
    }

    string getModel() { return model; }
    int getSpeed() { return speed; }

    float timeToCover(float distance) {
        return distance / speed;
    }
};

class Car : public Vehicle {};
class Bike : public Vehicle {};

int main() {
    Car c;
    Bike b;

    c.setData("Hyundai i20", 60);
    b.setData("Honda Shine", 40);
    

    cout << "Car Time:  " << c.timeToCover(120) << " hours\n";
    cout << "Bike Time: " << b.timeToCover(120) << " hours\n";

    return 0;
}