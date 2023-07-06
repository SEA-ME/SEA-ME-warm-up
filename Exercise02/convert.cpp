#include <iostream>
#include <string>
#include <algorithm>  // Required for std::transform function

int main(int argc, char* argv[]) {
  // Check the number of command-line arguments
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " {command} {string}" << std::endl;
    return 1;
  }

  std::string command = argv[1];  // Retrieve the command argument
  std::string str = argv[2];      // Retrieve the string argument

  // Convert the string to uppercase or lowercase based on the command
  if (command == "up") {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  } else if (command == "down") {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  } else {
    // Handle the case of an invalid command
    std::cout << "Invalid command. Please use 'up' or 'down'." << std::endl;
    return 1;
  }

  // Output the converted string
  std::cout << "Output: " << str << std::endl;

  return 0;
}
