#include <iostream>
#include <memory>
#include <vector>
#include <string>


/**
 * @brief Base class for all car parts.
 * 
 * This class serves as a base class for different types of car parts, providing a common interface
 * for printing details of the parts. It includes a pure virtual function that must be implemented
 * by derived classes.
 */
class Part {
public:
    /**
     * @brief Pure virtual function to print details of the part.
     * 
     * Derived classes must override this function to provide specific implementation for printing
     * the details of the particular part.
     */
    virtual void print() const = 0;
    
    /**
     * @brief Virtual destructor for proper cleanup of derived class objects.
     * 
     * Ensures that derived class destructors are called when deleting through a base class pointer.
     */
    virtual ~Part() {}
};

/**
 * @brief Derived class representing an Engine part of a car.
 */
class Engine : public Part {
public:
    /**
     * @brief Constructs an Engine object with specified horsepower and type.
     * 
     * @param horsepower The horsepower of the engine.
     * @param type The type of engine (e.g., "V12").
     */
    Engine(int horsepower, const std::string& type) : horsepower_(horsepower), type_(type) {}
    
    /**
     * @brief Prints details of the Engine part.
     * 
     * Outputs the horsepower and type of the engine.
     */
    void print() const override {
        std::cout << "Engine: " << horsepower_ << " HP, " << type_ << std::endl;
    }
    
private:
    int horsepower_; ///< The horsepower of the engine.
    std::string type_; ///< The type of the engine.
};

/**
 * @brief Derived class representing a Wheel part of a car.
 */
class Wheel : public Part {
public:
    /**
     * @brief Constructs a Wheel object with specified size and type.
     * 
     * @param size The size of the wheel in inches.
     * @param type The type of wheel (e.g., "Alloy").
     */
    Wheel(int size, const std::string& type) : size_(size), type_(type) {}
    
    /**
     * @brief Prints details of the Wheel part.
     * 
     * Outputs the size and type of the wheel.
     */
    void print() const override {
        std::cout << "Wheel: " << size_ << " inches, " << type_ << std::endl;
    }
    
private:
    int size_; ///< The size of the wheel in inches.
    std::string type_; ///< The type of the wheel.
};

/**
 * @brief Derived class representing a Brake part of a car.
 */
class Brake : public Part {
public:
    /**
     * @brief Constructs a Brake object with a specified type.
     * 
     * @param type The type of brake (e.g., "Disc").
     */
    Brake(const std::string& type) : type_(type) {}
    
    /**
     * @brief Prints details of the Brake part.
     * 
     * Outputs the type of the brake.
     */
    void print() const override {
        std::cout << "Brake: " << type_ << std::endl;
    }
    
private:
    std::string type_; ///< The type of the brake.
};

/**
 * @brief Derived class representing a Transmission part of a car.
 */
class Transmission : public Part {
public:
    /**
     * @brief Constructs a Transmission object with a specified type.
     * 
     * @param type The type of transmission (e.g., "Automatic").
     */
    Transmission(const std::string& type) : type_(type) {}
    
    /**
     * @brief Prints details of the Transmission part.
     * 
     * Outputs the type of the transmission.
     */
    void print() const override {
        std::cout << "Transmission: " << type_ << std::endl;
    }
    
private:
    std::string type_; ///< The type of the transmission.
};


/**
 * @brief Represents a car with various parts such as engine, wheels, brakes, and transmission.
 */
class Car {
public:
    /**
     * @brief Constructs a Car object with the specified attributes and parts.
     * 
     * @param make The make of the car (e.g., "Toyota").
     * @param model The model of the car (e.g., "Corolla").
     * @param year The manufacturing year of the car.
     * @param engine A shared pointer to the Engine part of the car.
     * @param wheels A vector of shared pointers to the Wheel parts of the car.
     * @param brakes A vector of shared pointers to the Brake parts of the car.
     * @param transmission A shared pointer to the Transmission part of the car.
     */
    Car(const std::string& make, const std::string& model, int year,
        std::shared_ptr<Engine> engine, std::vector<std::shared_ptr<Wheel>> wheels,
        std::vector<std::shared_ptr<Brake>> brakes, std::shared_ptr<Transmission> transmission)
        : make_(make), model_(model), year_(year), 
          engine_(engine), wheels_(wheels), brakes_(brakes), transmission_(transmission) {}

    /**
     * @brief Prints the details of the car and all its parts.
     * 
     * This function outputs the car's make, model, and year, followed by details of the engine,
     * each wheel, each brake, and the transmission.
     */
    void printParts() const {
        // Print the car's make, model, and year.
        std::cout << "Car: " << make_ << " " << model_ << " " << year_ << std::endl;
        
        // Print details of the Engine part.
        engine_->print();
        
        // Iterate over each wheel and print its details.
        for (const auto& wheel : wheels_) {
            wheel->print();
        }
        
        // Iterate over each brake and print its details.
        for (const auto& brake : brakes_) {
            brake->print();
        }
        
        // Print details of the Transmission part.
        transmission_->print();
    }

private:
    /**
     * @brief The make of the car.
     */
    std::string make_;
    
    /**
     * @brief The model of the car.
     */
    std::string model_;
    
    /**
     * @brief The manufacturing year of the car.
     */
    int year_;
    
    /**
     * @brief A shared pointer to the Engine part.
     */
    std::shared_ptr<Engine> engine_;
    
    /**
     * @brief A vector of shared pointers to the Wheel parts.
     */
    std::vector<std::shared_ptr<Wheel>> wheels_;
    
    /**
     * @brief A vector of shared pointers to the Brake parts.
     */
    std::vector<std::shared_ptr<Brake>> brakes_;
    
    /**
     * @brief A shared pointer to the Transmission part.
     */
    std::shared_ptr<Transmission> transmission_;
};
;

int main() {
    // Create an engine with 700 horsepower and type V12
    auto engine = std::make_shared<Engine>(700, "V12"); // auto: is used for type inference, so the compiler automatically deduces that engine is of type std::shared_ptr<Engine>.

    // Create a vector of 4 wheels, each of size 20 inches and type Alloy
    std::vector<std::shared_ptr<Wheel>> wheels;
    for (int i = 0; i < 4; ++i) {
        wheels.push_back(std::make_shared<Wheel>(20, "Alloy"));
    }

    // Create a vector of 4 disc brakes
    std::vector<std::shared_ptr<Brake>> brakes;
    for (int i = 0; i < 4; ++i) {
        brakes.push_back(std::make_shared<Brake>("Disc"));
    }

    // Create a transmission of type Automatic
    auto transmission = std::make_shared<Transmission>("Automatic");

    // Create a Car object with make Ferrari, model 488, year 2021, and the parts created above
    Car myCar("Ferrari", "488", 2021, engine, wheels, brakes, transmission);

    // Display details of all parts of the car
    myCar.printParts();

    return 0;
}

/**-------------------------Appendix-------------------------------
 * 
 *  V6 Engine: Common in many sports and luxury cars.
    V8 Engine: Found in performance and muscle cars.
    Electric Motor: Used in electric vehicles.
    Turbocharged Inline-4: Often used in compact sports cars****/
/**
 *  Alloy Wheels: Lightweight and stylish, common in many modern cars.
    Steel Wheels: Durable and often used in budget-friendly or utility vehicles.
    Chrome Wheels: Shiny and often used for aesthetic purposes.
    Off-Road Wheels: Larger and more rugged, designed for off-road vehicles.
 * **/

/**
 *  Disc Brakes: Common in most modern vehicles for better stopping power.
    Drum Brakes: Typically found on older or budget vehicles.
    Carbon-Ceramic Brakes: High-performance brakes used in sports and luxury cars.
    Anti-lock Braking System (ABS): Advanced braking system that prevents wheel lockup.
**/

/**
    Manual Transmission: Traditional transmission with a clutch and gear stick.
    Automatic Transmission: Shifts gears automatically, common in many vehicles.
    Continuously Variable Transmission (CVT): Provides smooth acceleration by varying gear ratios seamlessly.
    Dual-Clutch Transmission (DCT): Offers faster gear changes and is commonly used in sports cars.
**/



