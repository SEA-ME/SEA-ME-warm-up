#include <iostream>
#include <algorithm>
#include <vector>

bool validate_command(const std::string&);
std::string uppercase_string(const std::string&);
std::string lowercase_string(const std::string&);

// Available commands
const std::vector<std::string> commands = { "up", "down" };

int main(int argc, char** argv)
{
    if(argc < 3) {
        std::cout << "Example usage: ./convert {command} {string}" << std::endl;
        return 1;
    }

    const std::string command(argv[1]);

    if(!validate_command(command)) {
        std::cout << "Invalid command" << std::endl;
        return 1;
    }

    // Copying all arguments into a container of strings
    std::vector<std::string> text(argv + 2, argv + argc);

    // UP
    if(command == commands[0]) {
        transform(text.begin(), text.end(), text.begin(), ::uppercase_string);
    }
    // DOWN
    else if(command == commands[1]) {
        transform(text.begin(), text.end(), text.begin(), ::lowercase_string);
    }
    // FUTURE UNIMPLEMENTED COMMANDS
    else {
        std::cout << "Operation not implemented\n";
    }

    // Printing the changed text
    for (const auto & i : text) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

bool validate_command(const std::string& command) {
    if(find(commands.begin(), commands.end(), command) != commands.end()) {
        return true;
    }

    return false;
}

std::string uppercase_string(const std::string& str) {
    std::string s2(str.size(), '.');
    transform(str.begin(), str.end(), s2.begin(), ::toupper);
    return s2;
}

std::string lowercase_string(const std::string& str) {
    std::string s2(str.size(), '.');
    transform(str.begin(), str.end(), s2.begin(), ::tolower);
    return s2;
}
