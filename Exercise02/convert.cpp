#include <iostream>
#include <string>
#include <algorithm>  // Required for string transformation

int main() {
  // Ask the user for a command and a string
  std::cout << "Enter a command ('up' or 'down'): ";
  std::string command;
  std::cin >> command;
  
  std::cout << "Enter a string: ";
  std::string str;
  std::cin.ignore(); // Ignore the newline character in the input buffer
  std::getline(std::cin, str);

  // Convert the string based on the command
  if (command == "up") {
    // Convert the string to uppercase
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  } else if (command == "down") {
    // Convert the string to lowercase
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  } else {
    // Handle the case of an invalid command
    std::cout << "Invalid command. Please use 'up' or 'down'." << std::endl;
    return 1; // Exit the program with an error code
  }

  // Display the converted string
  std::cout << "Converted string: " << str << std::endl;

  return 0; // Exit the program successfully
}
