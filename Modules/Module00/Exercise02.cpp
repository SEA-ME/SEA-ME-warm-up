#include <iostream>
#include <string>   // Include the string library for std::string
#include <cctype>   // Include the cctype library for std::toupper


// Function to convert string to uppercase
void toUpperCase(std::string& str) {
    for (char& c : str) { // Loop through each character in the string 'str'
        c = std::toupper(static_cast<unsigned char>(c)); // Convert character to uppercase
    }
}

// Function to convert string to lowercase
void toLowerCase(std::string& str) {
    for (char& c : str) { // Loop through each character in the string 'str'
        c = std::tolower(static_cast<unsigned char>(c)); // Convert character to lowercase
    }
}

// Main function where the program starts execution
int main() {
    std::string str1 = "I'M THE ONE!"; // Declare and initialize a string variable 'str1'
    std::string str2 = "I'm A SMall man"; // Declare and initialize a string variable 'str2'

    // Convert string to uppercase and to lowercase
    toUpperCase(str1);
    toLowerCase(str2);

    // Output the converted string
    std::cout << "output: " << str1 << std::endl;
    std::cout << "output: " << str2 << std::endl;

    return 0; // Return 0 to indicate successful program execution
}


