# SEA:ME warm up Module 02

# Contents

### [**EX00.** Orthodox Canonical Form](#exercise-00--orthodox-canonical-form)
### [**EX01.** It’s racing party time!](#exercise-01--its-racing-party-time)
### [**EX02.** SuperBooster!](#exercise-02--superbooster)
### [**EX03.** I want SUPER RacingCar!](#exercise-03--i-want-super-racingcar)
### [**EX04.** Let’s roll the RacingCar](#exercise-04--lets-roll-the-racingcar)
### [**EX05.** The car has something to say](#exercise-05--the-car-has-something-to-say)
### [**EX06.** Accel and Break](#exercise-06--accel-and-break)
### [**EX07.** Convertor](#exercise-07--convertor)
### [**EX08.** Who is my real child?](#exercise-08--who-is-my-real-child)
### [**EX09.** The four fundamental arithmetic operations](#exercise-09--the-four-fundamental-arithmetic-operations)

# New rules
> From now on, all your classes must be designed in the Orthodox Canonical Form. The class would implement with these four required member functions: 
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

# Exercises

## Exercise 00 : Orthodox Canonical Form
> Every time C++ creates its few elements in the class when it compiles. After now your all class must be designed in **Orthodox Canonical Form.** Do you think it's annoying? This habit will reduce a part of your waste of time. Trust me!
Let’s start with a simple exercise.  

- Implement Car class
    - Member variable
        - name
        - speed
    - Member function
        - Constructor
        - Copy constructor
        - Copy assignment operator override
        - Destructor
- Make an example with main function

## Exercise 01 : It’s racing party time!
>The apple never falls far from the tree. Children tend to resemble their parents.
Inheritance is one of the most important concepts of **Object-Oriented Programming**. Let’s find out it in a racing game!

> Let's make awesome, horrible, sometimes weird cars. First, we probably need a basic car.  

1. Implement RacingCar Class
    - Member variable
        - Name
        - Max Health point(300)
        - Health point(current health point. This variable initializes Max health point)
        - Speed(1)
    - Member function
        - void GetDamage(unsigned int damage);
            - If the Health point is less than 0. fix it to 0.
<aside>
💡 Every member function has to print what happens
</aside>

## Exercise 02 : SuperBooster!

> Sometimes when renovating a car, get better results. Now time to upgrade our car. But from scratch is not so efficient. We have a cool car already! Use the cool car for our special upgrade car

1. Implement BoostCar
    - BoostCar will inherit everything from Car
    - Member variable
        - Name
        - Health point(200)
        - Health point(current health point. This variable initializes Max health point)
        - Speed(2)
    - BoostCar has special skills
        - void Booster(void)
            - Speed up the car for a moment.
            - After 2second, turn back the speed.
2. One more Car
    - Now Implement your own RacingCar your Car should inherit RacingCar and should have particular skills
    - If you want you can make more RacinCars as you want

<aside>
💡 Don’t forget! Every member function has to print what happens.

</aside>

## Exercise 03 :  I want SUPER RacingCar!

> Now Let’s equip some weapons in our RacingCar! It might be boring to just run the car. we need a weapon to sabotage others.

- First add this function in Car class.
    - void Attack(const RacingCar &target);
        - this function should call the target’s GetDamage(); function.
- Complete the definition of the following AExtraWeapon class and implement the necessary member functions.
    
    ```cpp
    class AExtraWeapon
    {
    protected:
        std::string name;
        int damage;
        int energy;
        RacingCar *parent;
    
    public:
        [...]
        std::string const &getName() const;
        
        virtual void Attack(const RacingCar& target);
        virtual AExtraWeapon* clone() = 0;
    };
    ```
    
    - Before making ExtraWeapons add an AExtraWeapon variable in RacingCar class. It can be an array or just one pointer. It doesn’t matter!
    - Their member function clone() will return a new instance of the same type.
    - Example of ExtraWeapon
        - WaterBomb, TargetMagnet, HealingFactor… etc.

<aside>
💡 Don’t forget! Every member function has to print what happens.
</aside>

## Exercise 04 : Let’s roll the RacingCar

> Now we need a track to roll RacingCars. Make it like a real racing game. 

- First, add the coordinates variable and Move function in RacingCar class.
    - Move function should move the RacingCar with their speed
- Make the track follow this Interface.
    
    ```cpp
    class ITrack
    {
    public:
        virtual ~ITrack() {}
        virtual void MoveCar(const RacingCar& car) = 0;
    };
    ```
    
    - MoveCar function calls RacingCar’s Move function
    - The track should have width and height, which means the track's max width and height.
    - MoveCar calls the Move function which is in the RacingCar class. All tracks have their own special work.
- Every track should have its own characteristics.
    - example) RacingCar move in SnowTrack speed + 1
- At least, make 2 tracks

<aside>
💡 For evaluation, Make enough main function by yourself. Simulate Car racing.
</aside>

## Exercise 05 : The car has something to say
> Do you remember the car that you made before? Now It’s time to expand the car.
Using getter() every time to debug class elements is often inefficient. Our great c++ provides operator overriding.

- Your Car class will work like this.
```c++
int main()
{
	Car car1;
	Car car2;
	
	std::cout << car1 << std::endl;
	std::cout << car2 << std::endl;
};
```
- And print follow like this:  
    <img width="200" alt="image" src="https://user-images.githubusercontent.com/54701846/217554160-53a1a651-13fc-4862-99ee-85ec82177d00.png"> 

<aside>
💡 You already know the speed could be changed by yourself
</aside>  


## Exercise 06 : Accel and Break
> If we call ChangeSpeed(); or SetSpeed() every time when we want to change the speed. It’s not so cool. We can more easily change the speed.  

- Your main function follows like this
```cpp
int main()
{
	Car car1;
	
	std::cout << car1 << std::endl;
	car1++;
	std::cout << car1 << std::endl;

	Car car2;
	
	std::cout << car2 << std::endl;
	car2--;
	std::cout << car2 << std::endl;

	std::cout << car1 << std::endl;
	car1 += 30;
	std::cout << car1 << std::endl;
};
```
<aside>
💡 You can decide how much speed change
</aside>  

## Exercise 07 : Convertor

> You've been using C-style casting until now? It doesn't look good. 
> Make a converter program. Follow this:
- The program receives two arguments
    1. Type of data to be transformed
        - The data types allowed are as follows.
            - int, float, char, double
    2. number
        - Examples of the output of the data type are as follows.
            - int: 0, -42, 42, 21 …
            - float: 0.0f, -4.2f, 4.2f …
            - char: ‘c’, ‘a’, ‘f’, ‘F’ …
            - double: 0.0, 4.2, 42.0 …
- It would work like this
```bash
./converter float 4

4 to change float
result: 4.0f
```
## Exercise 08 : Who is my real child?
> Do you remember the Car class? Now it's time to find their children.

- Make a few cars. These cars inherit the Car class. Make at least 3.
- Implement functions
    - Car* generator(void);
        - This function randomly instantiates one of your cars and returns the instance as a Car pointer.
    - void identify(Car* c);
        - It prints the actual type of the object pointed to by c: one of your cars
    - void identify(Car& c);
    - It prints the actual type of the object pointed to by c: one of your cars
    Using a pointer inside this function is forbidden.
## Exercise 09 : The four fundamental arithmetic operations

> We often use quadratic arithmetic. Of course, C++ already enables this with only a few symbols, but let's make it ourselves this time.
- Make four function
    - Add, subtract, multiply, divide
    - These 4 functions can get any type of value and get 2 arguments.
    - The two arguments must have the same type and must support all the comparison operators.
- And we want min(), max() function for any type. Make It also.
    - These functions return the correct one value.