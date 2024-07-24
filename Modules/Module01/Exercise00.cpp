#include <iostream>   // for std::cout
#include <string>


class Car{
private:
    std::string name;
    int speed;

public:

    // Constructor
    Car(const std::string& name, int speed) : name(name), speed(speed) {
        std::cout << "Car created: " << this->name << " with speed " << this->speed << std::endl;
    }

    // Copy Constructor
    Car(const Car& other) : name(other.name), speed(other.speed) {
        std::cout << "Car copied: " << this->name << " with speed " << this->speed << std::endl;
    }

    // Copy Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            name = other.name;
            speed = other.speed;
            std::cout << "Car assigned: " << this->name << " with speed " << this->speed << std::endl;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        std::cout << "Car destroyed: " << this->name << std::endl;
    }

    // Function to display car details
    void display() const {
        std::cout << "Car name: " << name << ", Speed: " << speed << std::endl;
    }

};

int main(){

    // Create a Car object using constructor
    Car car1("VW", 160);
    car1.display();


    // Create a Car object using copy constructor
    Car car2 = car1;
    car2.display();

    // Create another Car object
    Car car3("Honda", 140);

    // Use copy assignment operator
    car3 = car1;
    car3.display();

    return 0;
}