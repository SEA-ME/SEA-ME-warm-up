#include <iostream>
#include <memory>  // For std::unique_ptr
#include <string>

// Base class: Car
class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    // Constructor
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {}

    // Method to display car details
    void display() const {
        std::cout << "Car: " << make << " " << model << " " << year << std::endl;
    }

    // Destructor
    ~Car() {}
};

int main() {
    // Create a Car object using std::unique_ptr
    std::unique_ptr<Car> car = std::make_unique<Car>("VW", "Caddy", 2020);

    car->display();
    
    // Create a Car object using std::shared_ptr
    std::shared_ptr<Car> car1 = std::make_shared<Car>("Hyundai", "i20", 2021);

    // Display the initial reference count
    // std::cout << "Reference count for car1: " << car1.use_count() << std::endl;

    std::shared_ptr<Car> car2 = car1;

    // // Display the reference count after creating car2
    // std::cout << "Reference count for car1: " << car1.use_count() << std::endl;
    // std::cout << "Reference count for car2: " << car2.use_count() << std::endl;

    // Use the car objects
    car1->display();
    car2->display();
    // std::cout << "the address of car1 is " << car1 << std::endl;
    // std::cout << "the address of car2 is " << car2 << std::endl;

    // No need to explicitly delete the car object
    // It will be automatically deleted when `car` goes out of scope

    return 0;
}
