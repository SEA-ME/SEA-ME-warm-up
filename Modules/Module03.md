# SEA:ME warm up Module 03

# Contents

### [**EX00.** Smart Pointer](#exercise-00--smart-pointer)
### [**EX01.** Design your own Car](#exercise-01--design-your-own-car)

# Exercises

## Exercise 00 : Smart Pointer

> What is the best way to understand something? I think the fastest way is to make it yourself.
C++ has created smart pointers for developers who each time cause memory leaks (how many developers were wasting memory...) Smart pointers are simple, powerful, and even more efficient than garbage collectors in other languages.
Let's make our own way of how this amazing smart pointer works.
- Implement Smart pointer
    - unique_ptr
    - shared_ptr
- Follow the standard documents
- Requirements
    - The namespace must be **ft**

<aside>
💡 If you lost the way, these two reference links will be your angel  

[https://www.cplusplus.com/](https://www.cplusplus.com/)  
[https://cppreference.com/](https://cppreference.com/)
</aside>

## Exercise 01 : Design your own Car
> Now It’s time to use all skills that you learn before!

- The Car class shall have the following elements and each element have the following traits:
    - Wheel
        - durability(int)
        - angle(float)
    - Door
        - durability(int)
        - open(bool)
        - lock(bool)
        - Window(Window)
            - open(bool)
        - The Door class also includes trunks.
    - Light
        - durability(int)
        - intensity(int)
        - position(std::string)
- The durability is between zero and 100.
- Feel free to implement functions that can simulate a car.
- Prove your Car in the main function.

<aside>
💡 Look out what is the Component pattern

</aside>
