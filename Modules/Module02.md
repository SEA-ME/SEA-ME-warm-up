# Module 02
## Exercise 00 : Smart Pointer

> A smart pointer is a class template that provides automatic memory management for dynamically allocated objects. It is a type of RAII (Resource Acquisition Is Initialization) object that ensures that memory allocated to an object is automatically freed when the smart pointer goes out of scope.
> Expand your Car example to demonstrates how smart pointers can be used in C++ to automate memory management and avoid common problems like memory leaks and dangling pointers.

<aside>
💡 What is memory leak? And what is a dangling pointer?
</aside>

## Exercise 01 : Model your own Car
> Now It’s time to use all the skills that you learn till now!

- Model a car with all its parts using OOP concepts in C++. You can begin by defining a Part base class to represent the parts that make up the car, such as the engine, wheels, brakes, and so on. Each part has its own unique properties and behavior, which you can model using inheritance and polymorphism.

Here is an example implementation of the Part class:
```
class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};
```
The Part class has a pure virtual function print() that will be overridden by the derived classes.

Now, let's define a derived class for the Engine part:
```
class Engine : public Part {
public:
    void print() override {
        cout << "Engine part\n";
    }
};
```
The Engine class inherits from the Part class and overrides the print() function to print the name of the part.

Similarly, we can define other derived classes for the other parts of the car, such as the Wheel, Brake, Transmission, etc.:
```
class Wheel : public Part {
public:
    void print() override {
        cout << "Wheel part\n";
    }
};

class Brake : public Part {
public:
    void print() override {
        cout << "Brake part\n";
    }
};

class Transmission : public Part {
public:
    void print() override {
        cout << "Transmission part\n";
    }
};
```
Now that we have defined the different parts of the car, we can define the Car class that contains these parts:
```
class Car {
public:
    Car() {
        engine_ = new Engine();
        wheels_ = new Wheel[4];
        brakes_ = new Brake[4];
        transmission_ = new Transmission();
    }
    
    void printParts() {
        engine_->print();
        for (int i = 0; i < 4; ++i) {
            wheels_[i].print();
            brakes_[i].print();
        }
        transmission_->print();
    }
    
    ~Car() {
        delete engine_;
        delete [] wheels_;
        delete [] brakes_;
        delete transmission_;
    }
    
private:
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};
```
The Car class contains member variables for each of the parts, which are initialized in the constructor. The printParts() function prints the name of each part of the car, and the destructor frees the memory allocated for the parts using delete.

Now, we can create a Car object and print its parts:
```
int main() {
    Car myCar;
    myCar.printParts();
    
    return 0;
}
```
This example demonstrates how to model a car using OOP concepts in C++. Now by encapsulating the parts within a Car object, create a more complex, composite object that represents the entire car. Details is what seperate the best from ordinary! Name your favourite car and model it here. IN DETAIL.

## Evaluation Form
> Fill in this [Evaluation Form Module02](https://docs.google.com/forms/d/e/1FAIpQLSdJkHc_MgfpEgoUdVlT6oPu2iAD6us6nGz4OglAINpUJKSMXw/viewform). **You need to collect 2 feedbacks from 2 peers from other than your own team**.
