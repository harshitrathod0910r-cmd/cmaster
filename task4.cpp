#include <iostream>
using namespace std;

class Vehicle {
public:
    string model;
    int speed;

    void setData(string m, int s) {
        model = m;
        speed = s;
    }

    virtual void displayDetails() {
        cout << "Vehicle Model: " << model << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car : public Vehicle {
public:
    void displayDetails() {
        cout << "Car Model: " << model << endl;
        cout << "Car Speed: " << speed << endl;
    }
};

class Bike : public Vehicle {
public:
    void displayDetails() {
        cout << "Bike Model: " << model << endl;
        cout << "Bike Speed: " << speed << endl;
    }
};

int main() {
    Vehicle *h[2];

    Car c;
    Bike b;

    c.setData("creata", 120);
    b.setData("pulsar", 80);

    h[0] = &c;
    h[1] = &b;

    for(int i = 0; i < 2; i++) {
        h[i]->displayDetails();
        cout <<endl;
    }

    return 0;
}