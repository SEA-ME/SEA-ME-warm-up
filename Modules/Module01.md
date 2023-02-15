# SEA:ME warm up Module 01

# Contents

### [Brrrrrng](#exercise-00--brrrrrng)
### [Car factory](#exercise-01--car-factory)
### [Transformable?](#exercise-02--transformable)
### [“Mix, mix, swirl, mix”](#exercise-03--mix-mix-swirl-mix)


# Exercises

## Exercise 00 : Brrrrrng
> I always think what it would be like to have a nice supercar. It must have a brilliant color that anyone can only look back on and a loud sound that makes everyone turn their heads. What should I name it? That would be so nice!!

> Make a **Car** for me!!
- The car would have a **name** and **color**.

> And when I **Accelerate(void)** the Car It would make a sound like this!

- {name} : Brrrrrrng!!!!

> For the others, Make it automatically! Try to make these!

- Car* newCar(std::string name, std::string color);
    - It creates a car, name, color it, and return it so you can use it outside of the function scope
- void randomCar(std::string name, std::string color);
    - It creates a car, name, color it, and accelerate itself.

## Exercise 01 : Car factory

> I think only the car is not enough. Let's build a factory.
The **CarFactory** has a name. And we need to save **Car types**. **Dynamic array** is the best choice!

> And CarFactory should have some functions for changing the car list and selling our cars.
follow this: 

- void AddCarType(std::string name, std::string color);
    - Add a new type of car to the array
    - Car’s name must be unique
- void  DeleteCarType(std::string name);
    - Delete a car that match with name
- Car* PickNewCar(std::string name, std::string color);
    - It make new car in array and return Car* pointer. If there are no match name function return NULL and print error message.
    - If color is none make car with default color.

## Exercise 02 : Transformable?
> Do you know a Cute yellow little BumbleBee? He can change his body like a chameleon.

1. Implement BumbleBee class.
    - Member variable
        - string private attribute type
        - string private attribute color
        - int private attribute max speed
        - int private attribute seat
    - Member function
        - void printStatus( void );
            - This function print current status of class.
        - Setter
        - Getter
2. Implementation 3 functions
    - Following name
        - TransformBeeV
        - TransformBeeR
        - TransformBeeP
    - If your implementation is correct, executing the following code will print like this
    You can change Bee’s contents as you want.

<img width="400" alt="image" src="https://user-images.githubusercontent.com/54701846/217396128-ad543814-7d79-49c2-9bba-00db3d3248c6.png"> 

<img width="400" alt="image" src="https://user-images.githubusercontent.com/54701846/217396207-45c991e5-99bf-4026-84df-c83bfdfe47d8.png"> 


## Exercise 03 : “Mix, mix, swirl, mix”
> There are times when I have to fix a lot of things while working on files. If you fix it with your hands all of that... I hope you don't say you are a programmer. Look, we can make an awesome program! That's why we are a programmer.

-  Make program.
    1. remove
        - It takes 2 arguement
            1. filename
            2. string
        - this program remove string1 in file
    2. add
        - It takes 2 arguement
            1. filename
            2. string
    3. replace
        - It takes 3 arguement
            1. filename. 
            2. string1
            3. string2
        - this program replace string1 to string2 in file
-  Every program can get -n option. If program get -n option the result must make with new file follow filename_{n}.
    1. filename_{n} → n is the first available number. It starts with 1.