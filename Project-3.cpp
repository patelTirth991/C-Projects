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
    Vehicle() {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, const string& manu, const string& mod, int y) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
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

    virtual void input() {
        cout << "Enter Vehicle ID: "; cin >> vehicleID;
        cout << "Enter Manufacturer: "; cin >> ws; getline(cin, manufacturer);
        cout << "Enter Model: "; getline(cin, model);
        cout << "Enter Year: "; cin >> year;
    }

    virtual void display() const {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
private:
    char fuelType;

public:
    void setFuelType(char f) { fuelType = f; }
    char getFuelType() const { return fuelType; }

    void input() override {
        Vehicle::input();
        cout << "Enter Fuel Type (P/D/E): "; cin >> fuelType;
    }

    void display() const override {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    void setBatteryCapacity(int b) { batteryCapacity = b; }
    int getBatteryCapacity() const { return batteryCapacity; }

    void input() override {
        Car::input();
        cout << "Enter Battery Capacity (in kWh): "; cin >> batteryCapacity;
    }

    void display() const override {
        Car::display();
        cout << "\nBattery Capacity: " << batteryCapacity << " kWh";
    }
};

class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    void setTopSpeed(int s) { topSpeed = s; }
    int getTopSpeed() const { return topSpeed; }

    void input() override {
        ElectricCar::input();
        cout << "Enter Top Speed (in km/h): "; cin >> topSpeed;
    }

    void display() const override {
        ElectricCar::display();
        cout << "\nTop Speed: " << topSpeed << " km/h";
    }
};

class Aircraft {
private:
    int flightRange;

public:
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
    void input() {
        Car::input();
        inputAircraft();
    }

    void display() const {
        Car::display();
        displayAircraft();
    }

    int getID() const {
        return Car::getVehicleID(); 
    }
};

class Sedan : public Car {
public:
    void input() override {
        Car::input();
    }

    void display() const override {
        Car::display();
    }
};

class SUV : public Car {
public:
    void input() override {
        Car::input();
    }

    void display() const override {
        Car::display();
    }
};

class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() { count = 0; }

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
    }

    void addVehicle() {
        int choice;
        cout << "\nSelect Vehicle Type to Add:";
        cout << "\n1. Car\n2. Electric Car\n3. Sports Car\n4. Flying Car\n5. Sedan\n6. SUV";
        cout << "\nEnter choice: "; cin >> choice;

        Vehicle* v = NULL;

        switch (choice) {
            case 1: v = new Car(); break;
            case 2: v = new ElectricCar(); break;
            case 3: v = new SportsCar(); break;
            case 4: v = new FlyingCar(); break;
            case 5: v = new Sedan(); break;
            case 6: v = new SUV(); break;
            default: cout << "Invalid choice!"; return;
        }

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
