#include <iostream>
#include <string>   // Include the string library for std::string
#include <cctype>   // Include the cctype library for character conversion functions

// Define preprocessing conditions
// #define normal
#define OOP

#ifdef normal
// The 'normal' section of the code handles basic string manipulation functions

// Function to convert a given string to uppercase
void toUpperCase(std::string& str) {
    for (char& c : str) { // Iterate through each character in the string 'str'
        c = std::toupper(static_cast<unsigned char>(c)); // Convert the character to uppercase
    }
}

// Function to convert a given string to lowercase
void toLowerCase(std::string& str) {
    for (char& c : str) { // Iterate through each character in the string 'str'
        c = std::tolower(static_cast<unsigned char>(c)); // Convert the character to lowercase
    }
}

// Main function - Entry point of the program
int main() {
    std::string str1 = "I’M THE ONE!"; // Initialize string 'str1' with an example value
    std::string str2 = "I’m A SMall man"; // Initialize string 'str2' with another example value

    // Convert 'str1' to uppercase and 'str2' to lowercase
    toUpperCase(str1);
    toLowerCase(str2);

    // Output the converted strings
    std::cout << "output: " << str1 << std::endl; // Display the uppercase string
    std::cout << "output: " << str2 << std::endl; // Display the lowercase string

    return 0; // Return 0 to indicate successful execution
}

#endif

#ifdef OOP
// The 'OOP' section of the code demonstrates object-oriented programming (OOP) with string manipulation

#include <iostream>
#include <string>

// Class to encapsulate string operations
class MyString {
private:
    std::string str; // Private member variable to store the string

public:
    // Method to convert the internal string to uppercase
    void toUpperCase() {
        for (char& c : str) {
            c = std::toupper(static_cast<unsigned char>(c)); // Convert each character to uppercase
        }
    }

    // Method to convert the internal string to lowercase
    void toLowerCase() {
        for (char& c : str) {
            c = std::tolower(static_cast<unsigned char>(c)); // Convert each character to lowercase
        }
    }

    // Method to replace a substring within the internal string
    void ReplaceString(std::int8_t i, std::int8_t n, const std::string& str1) {
        str.replace(i, n, str1); // Replace part of the string with 'str1'
    }

    // Method to set the internal string value
    void setString(const std::string& s) {
        str = s; // Assign the provided string to the internal variable
    }

    // Method to get the internal string value
    std::string getString() const {
        return str; // Return the internal string
    }
};

// Main function - Entry point of the program
int main() {
    MyString Sentence; // Create an instance of MyString named 'Sentence'
    Sentence.setString("I'm the one!"); // Initialize the internal string using setString method

    // Output the original string
    std::cout << "convert up " << Sentence.getString() << std::endl; 

    Sentence.toUpperCase(); // Convert the internal string to uppercase

    // Output the string in uppercase
    std::cout << "output: " << Sentence.getString() << std::endl; 

    Sentence.ReplaceString(0, 15, "I'm A SMall man"); // Replace a portion of the string with a new value

    // Output the modified string
    std::cout << "convert down " << Sentence.getString() << std::endl;

    Sentence.toLowerCase(); // Convert the string to lowercase

    // Output the final string in lowercase
    std::cout << "output: " << Sentence.getString() << std::endl;

    return 0; // Return 0 to indicate successful execution
}

#endif
