
#include <iostream>

using namespace std;

const double PI = 3.14;
const int MAX_MOVIES = 5;
const int NAME_LENGTH= 50;


class Vehicle {
private:
    char model[NAME_LENGTH]; // C-style string
    double speed; // Speed in km/h

public:
    // Constructor
    Vehicle(const char* m, double s) : speed(s) {
        // Manual copy for model name
        int i = 0;
        while (m[i] != '\0' && i < NAME_LENGTH - 1) { model[i] = m[i]; i++; }
        model[i] = '\0';
    }
    
    // Default constructor for array use
    Vehicle() : speed(0.0) { model[0] = '\0'; }

    // Public member functions (Getters)
    const char* getModel() const { return model; }
    double getSpeed() const { return speed; }

    // Pure virtual function for Task 4
    virtual void displayDetails() const = 0; // Makes Vehicle an Abstract Class

    // Virtual destructor 
    virtual ~Vehicle() {}
};

// Derived Class 1: Car
class Car : public Vehicle {
public:
    Car(const char* m, double s) : Vehicle(m, s) {}

    // Method to calculate time taken for a certain distance
    double calculateTime(double distance_km) const {
        return distance_km / getSpeed(); 
    }


    void displayDetails() const override {
        cout << "  Car Model: " << getModel() << ", Max Speed: " 
             << getSpeed() << " km/h (Type: Land Vehicle)" << endl;
    }
};

// Derived Class 2: Bike
class Bike : public Vehicle {
public:
    Bike(const char* m, double s) : Vehicle(m, s) {}

    // Method to calculate time taken for a certain distance
    double calculateTime(double distance_km) const {
        return distance_km / getSpeed();
    }

    // Implementation of virtual function for Task 4
    void displayDetails() const override {
        cout << "  Bike Model: " << getModel() << ", Max Speed: " 
             << getSpeed() << " km/h (Type: Two-Wheeler)" << endl;
    }
};

void Que3_demo() {
    cout << "---  Task 3: Inheritance & Abstraction ---" << endl;
    
    Car sedan("Honda Civic", 180.0);
    Bike sportsBike("Yamaha R1", 250.0);
    
    double travel_distance = 360.0; 
    
    double car_time = sedan.calculateTime(travel_distance);
    double bike_time = sportsBike.calculateTime(travel_distance);

    cout << "Distance to cover: " << travel_distance << " km" << endl;
    cout << "  Sedan (" << sedan.getSpeed() << " km/h): Time taken = " 
         << car_time << " hours" << endl;
    cout << "  Sports Bike (" << sportsBike.getSpeed() << " km/h): Time taken = " 
         << bike_time << " hours" << endl;
    cout << endl;
}

void Que4_demo() {
    cout << "---  Task 4: Polymorphism (Virtual Function) ---" << endl;


    Vehicle* fleet[MAX_MOVIES]; 
    int count = 0;


    fleet[count++] = new Car("Audi A4", 220.0);
    fleet[count++] = new Bike("Harley Davidson", 160.0);
    fleet[count++] = new Car("Tesla Model 3", 260.0);


    cout << "Demonstrating Polymorphism via Vehicle Pointers:" << endl;
    for (int i = 0; i < count; ++i) {
        fleet[i]->displayDetails();
    }

    // Clean up memory
    for (int i = 0; i < count; ++i) {
        delete fleet[i];
    }
    cout << endl;
}

int main() {
    
    Que3_demo(); 
    Que4_demo();
    return 0;

}
