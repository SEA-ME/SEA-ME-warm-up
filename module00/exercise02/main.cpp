#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool validate_command(const std::string&);
std::string uppercase_string(const std::string&);
std::string lowercase_string(const std::string&);

// Available commands
const std::vector<std::string> commands = { "up", "down" };

int main(int argc, char** argv)
{
    if(argc < 3) {
        cout << "Example usage: ./convert {command} {string}" << endl;
        return 1;
    }

    const string command(argv[1]);

    if(!validate_command(command)) {
        cout << "Invalid command" << endl;
        return 1;
    }

    // Copying all arguments into a container of strings
    vector<string> text(argv + 2, argv + argc);

    // UP
    if(command == commands[0]) {
        transform(text.begin(), text.end(), text.begin(), ::uppercase_string);
    }
    // DOWN
    else if(command == commands[1]) {
        transform(text.begin(), text.end(), text.begin(), ::lowercase_string);
    }

    // Printing the changed text
    for (const auto & i : text) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

bool validate_command(const string& command) {
    if(find(commands.begin(), commands.end(), command) != commands.end()) {
        return true;
    }

    return false;
}

string uppercase_string(const string& str) {
    string s2(str.size(), '.');
    transform(str.begin(), str.end(), s2.begin(), ::toupper);
    return s2;
}

string lowercase_string(const string& str) {
    string s2(str.size(), '.');
    transform(str.begin(), str.end(), s2.begin(), ::tolower);
    return s2;
}