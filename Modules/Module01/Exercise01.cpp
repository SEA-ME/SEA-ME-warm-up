#include <iostream>   // for std::cout
#include <string>


class Car{
protected:
    std::string make;
    std::string model;
    int year;

public:

    // Constructor
    Car(const std::string& make, const std::string& model, int year) : make(make), model(model), year(year) {}

    // Copy Constructor
    Car(const Car& other) : make(other.make), model(other.model), year(other.year) {}

    // Copy Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            make = other.make;
            model = other.model;
            year = other.year;
        }
        return *this;
    }

    // Destructor
    virtual ~Car() {
    }

    // Function to display car details
    void display() const {
        std::cout << "Car maker: " << make << ", Model: " << model << ", Year: " << year << std::endl;
    }

    virtual void drive() const{
        // Just print something like Driving "make" "model" "year" edition.
        std::cout << "Driving " << make << ", Model: " << model << ", Year: " << year << std::endl;
    }
};

class SportsCar : public Car {
private:
    int topSpeed;
public:
     // Constructor
    SportsCar(const std::string& make, const std::string& model, int year, int topSpeed) : Car(make,model,year), topSpeed(topSpeed) {}
 
    // Override drive function
    void drive() const override {
        std::cout << "Driving " << make << ", Model: " << model << ", Year: " << year << " edition at top speed of " << topSpeed << " km/h." << std::endl;
    }

    // Destructor
    ~SportsCar() override {}

};

int main(){

    // Create a Car object
    Car car1("VW", "Caddy", 2020);
    car1.drive();

    // Create a SportsCar object
    SportsCar sportsCar1("Ferrari", "488", 2021, 330);
    sportsCar1.drive();

    return 0;
}