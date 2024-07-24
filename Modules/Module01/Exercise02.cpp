#include <iostream>   // for std::cout
#include <string>

// 1. Encapsulation is used:
// Encapsulation is about bundling data and methods that operate on the data within 
// a single unit (class) and restricting access to some of the object s components. 
// This is done using access specifiers (private, protected, public).

// 2. Inheritance
// Inheritance allows a class to inherit attributes and methods from another class. 
// This promotes code reuse.

// 3. Polymorphism
// Polymorphism allows methods to do different things based on the object it is acting upon. 
// It is often achieved through method overriding and virtual functions.

// 4. Modularity
// Modularity refers to the organization of code into separate, manageable parts. 
// Each part (or module) can be developed and tested independently.


// 5. Abstraction


class Car{
protected:// 
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
    virtual ~Car() {}

    // Getter for make
    std::string getMake() const {
        return make;
    }

    // Getter for model
    std::string getModel() const {
        return model;
    }

    // Getter for year
    int getYear() const {
        return year;
    }

        // Setter for make
    void setMake(const std::string& make) {
        this->make = make;
    }

    // Setter for model
    void setModel(const std::string& model) {
        this->model = model;
    }

    // Setter for year
    void setYear(int year) {
        this->year = year;
    }

    // Function to display car details
    void display() const {
        std::cout << "Car: " << make << ", Model: " << model << ", Year: " << year << std::endl;
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