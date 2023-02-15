# SEA:ME warm up Module 00

# Contents

### [**EX00.** Welcome SEA:ME](#exercise-00--welcome-seame)
### [**EX01.** QT so cute](#exercise-01--qt-so-cute)
### [**EX02.** Do you know string?](#exercise-02--do-you-know-string)
### [**EX03.** Old PhoneBook](#exercise-03--old-phonebook)

# Exercises
## Exercise 00 : Welcome SEA:ME

> Now let’s explore [SEA:ME world](https://github.com/SEA-ME)! You can find everything of SEA:ME!

> First, find one repository for evaluating the warm up projects. This repository is one of the basic starts and It will guide your whole SEA:ME life.

- And follow this guide:

    1. Clone repository.
    2. Make your own branch. use your name or nickname or word that your special 
        - This branch is your workspace. And this branch will use when you get the evaluation.
        - Your branch must be derived from the special branch name of swimming.
    3. Add a file by your name. In this file, you should introduce yourself. And add a link in the [README.md](http://README.md) file. 
        - Add a link that your branch in the README file.
        - After in your introduction file, you should add a link for each Module.
    4. Push your work outcomes on Github and make a Pull Request to the swimming branch.
        - Make a Pull Request and get a review from 2 people.
        - You would get a merge conflict in the README file. In this case, merge yours and others. Don’t remove others’ results.

<aside>
💡 When you merge your branch there should be only two files, one is a README file and the other one is an introduction file.
</aside>

<aside>
💡 After every result is pushed to your branch.
</aside>

## Exercise 01 : QT so cute
> Do you know what is IDE? Probably you know. But do you know why use IDE?

> Let’s find it first!

> Now you know what is IDE? Then let’s find out what is QT!

> In the warm up, you should compile with qmake or CMake. So you should know it! But don't find it so deep. At this time, you need only what is QT and how to use it.

<aside>
💡 Install QT5. Only version 5 is allowed.
</aside>

## Exercise 02 : Do you know string??
> How deeply do you know about CPP? Let’s start from the beginning again.
The first one is just for using string. 

- Make the program as follows this:
    1. Use simple string class
        1. To convert UPPER CASE
        2. To convert LOWER CASE
    2. Use string class’s functions
        1. Substr, append, insert, replace, erase, etc..
    - The program gets two arguments:
        - ./convert {command} {string}
            - ex) `./convert up I’m the one!`
                - output:  `I’M THE ONE!`
            - ex) `./convert down I’m A SMall man`
                - output: `i’m a small man`

## Exercise 03 : Old PhoneBook

> Our older computers have no graphics. They only could use characters on the black screen.
Can you imagine? No graphics, No mouse. You don’t need to imagine it. Because now you will make yourself!

- You have to make a Phonebook application.  Follow the details:
    - User can use these commands
        - ADD
            - Add new contact in phonebook
            - Require contents
                1. Name
                2. Phone number(unique)
                3. Nickname
        - SEARCH
            - List up the contacts with index
                1. User choose index display details of the contact.
                2. If user want can bookmark the contact
        - REMOVE
            - Remove a contact with an index or a phone number.
        - BOOKMARK
            - List up the bookmarked contact
        - EXIT
            - Shut down the program
<aside>
💡 Try to make good use of the class.
</aside>
