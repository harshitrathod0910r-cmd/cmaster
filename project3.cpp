#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle() : vehicleID(0), manufacturer(""), model(""), year(0) {
        totalVehicles++;
    }

    Vehicle(int id, const string& manu, const string& mod, int y)
        : vehicleID(id), manufacturer(manu), model(mod), year(y) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    void setVehicleID(int id) { vehicleID = id; }
    void setManufacturer(const string& manu) { manufacturer = manu; }
    void setModel(const string& mod) { model = mod; }
    void setYear(int y) { year = y; }

    int getVehicleID() const { return vehicleID; }
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    static int getTotalVehicles() { return totalVehicles; }

    // helper input/display used by derived classes
    void input1() {
        cout << "Enter Vehicle ID: "; cin >> vehicleID;
        cout << "Enter Manufacturer: "; cin >> ws; getline(cin, manufacturer);
        cout << "Enter Model: "; getline(cin, model);
        cout << "Enter Year: "; cin >> year;
    }

    void display1() const {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }

    // FIX: virtual functions so callers using Vehicle* will dispatch correctly
    virtual void input() { input1(); }
    virtual void display() const { display1(); }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
private:
    char fuelType;

public:
    Car() : fuelType('P') {}

    void setFuelType(char f) { fuelType = f; }
    char getFuelType() const { return fuelType; }

    virtual void input() override {
        input1();
        cout << "Enter Fuel Type (P/D/E): "; cin >> fuelType;
    }

    virtual void display() const override {
        display1();
        cout << "\nFuel Type: " << fuelType;
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar() : batteryCapacity(0) {}

    void setBatteryCapacity(int b) { batteryCapacity = b; }
    int getBatteryCapacity() const { return batteryCapacity; }

    virtual void input() override {
        input1();
        cout << "Enter Fuel Type (P/D/E): "; char f; cin >> f; setFuelType(f);
        cout << "Enter Battery Capacity (in kWh): "; cin >> batteryCapacity;
    }

    virtual void display() const override {
        display1();
        cout << "\nFuel Type: " << getFuelType();
        cout << "\nBattery Capacity: " << batteryCapacity << " kWh";
    }
};

class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar() : topSpeed(0) {}

    void setTopSpeed(int s) { topSpeed = s; }
    int getTopSpeed() const { return topSpeed; }

    virtual void input() override {
        input1();
        cout << "Enter Fuel Type (P/D/E): "; char f; cin >> f; setFuelType(f);
        cout << "Enter Battery Capacity (in kWh): "; int bc; cin >> bc; setBatteryCapacity(bc);
        cout << "Enter Top Speed (in km/h): "; cin >> topSpeed;
    }

    virtual void display() const override {
        display1();
        cout << "\nFuel Type: " << getFuelType();
        cout << "\nBattery Capacity: " << getBatteryCapacity() << " kWh";
        cout << "\nTop Speed: " << topSpeed << " km/h";
    }
};

class Aircraft {
private:
    int flightRange;

public:
    Aircraft() : flightRange(0) {}

    void setFlightRange(int f) { flightRange = f; }
    int getFlightRange() const { return flightRange; }

    void inputAircraft() {
        cout << "Enter Flight Range (in km): "; cin >> flightRange;
    }

    void displayAircraft() const {
        cout << "\nFlight Range: " << flightRange << " km";
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    // override input/display from Vehicle (via Car)
    virtual void input() override {
        // call Vehicle helper via Car -> Vehicle
        input1();
        cout << "Enter Fuel Type (P/D/E): "; char f; cin >> f; setFuelType(f);
        inputAircraft();
    }

    virtual void display() const override {
        display1();
        cout << "\nFuel Type: " << getFuelType();
        displayAircraft();
    }

    // convenience
    int getID() const {
        return getVehicleID();
    }
};

class Sedan : public Car {
public:
    virtual void input() override {
        input1();
        cout << "Enter Fuel Type (P/D/E): "; char f; cin >> f; setFuelType(f);
    }

    virtual void display() const override {
        display1();
        cout << "\nFuel Type: " << getFuelType();
    }
};

class SUV : public Car {
public:
    virtual void input() override {
        input1();
        cout << "Enter Fuel Type (P/D/E): "; char f; cin >> f; setFuelType(f);
    }

    virtual void display() const override {
        display1();
        cout << "\nFuel Type: " << getFuelType();
    }
};

class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() : count(0) {
        for (int i = 0; i < 100; ++i) vehicles[i] = nullptr;
    }

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
    }

    void addVehicle() {
        if (count >= 100) {
            cout << "\nRegistry full! Cannot add more vehicles.\n";
            return;
        }

        int choice;
        cout << "\nSelect Vehicle Type to Add:";
        cout << "\n1. Car\n2. Electric Car\n3. Sports Car\n4. Flying Car\n5. Sedan\n6. SUV";
        cout << "\nEnter choice: "; cin >> choice;

        Vehicle* v = nullptr;

        switch (choice) {
            case 1: v = new Car(); break;
            case 2: v = new ElectricCar(); break;
            case 3: v = new SportsCar(); break;
            case 4: v = new FlyingCar(); break;
            case 5: v = new Sedan(); break;
            case 6: v = new SUV(); break;
            default: cout << "Invalid choice!"; return;
        }

        // Polymorphic call; correct virtual function will execute
        v->input();
        vehicles[count++] = v;
    }

    void viewVehicles() const {
        if (count == 0) {
            cout << "\nNo vehicles to display.";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "\nVehicle #" << (i + 1) << ":";
            vehicles[i]->display();
            cout << "\n----------------------";
        }
    }

    void searchById() const {
        int id;
        cout << "Enter Vehicle ID to search: "; cin >> id;
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "\nVehicle Found:";
                vehicles[i]->display();
                return;
            }
        }
        cout << "\nVehicle with ID " << id << " not found.";
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n\n--- Vehicle Registry System ---";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle by ID";
        cout << "\n4. Total Vehicles";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registry.addVehicle(); break;
            case 2: registry.viewVehicles(); break;
            case 3: registry.searchById(); break;
            case 4: cout << "Total Vehicles: " << Vehicle::getTotalVehicles(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 5);
    return 0;
}
