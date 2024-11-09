#include <iostream>
#include <map>
#include <sstream>
#include <future>
#include "phonebook.h"

Phonebook contacts {};

int parse_int(const std::string& str) {
    try {
        return stoi(str);
    }
    catch(...) {
        return -1;
    }
}

void add_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("n");
    if(it == options.end()){
        std::cout << "Name is required\n";
        return;
    }
    std::string name = it->second;

    it = options.find("p");
    if(it == options.end()){
        std::cout << "Phone number is required\n";
        return;
    }
    std::string phone_number = it->second;

    it = options.find("k");
    if(it == options.end()){
        std::cout << "Nickname is required\n";
        return;
    }
    std::string nickname = it->second;

    std::cout << "\nAdding user " << name << " " << phone_number << " " << nickname << "\n";
    contacts.add_contact(*make_unique<Contact> (name, phone_number, nickname));
}

void remove_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("i");
    bool removed;
    if(it == options.end()){
        it = options.find("p");
        if(it == options.end()){
            std::cout << "\nNo inputted id\n";
            return;
        }
        // Retrieve id of phone number (if not exists return)
        std::string phone = it->second;
        std::cout << "\nRemoving contact with phone number " << phone << "\n";
        removed = contacts.remove_contact(phone);
    }
    else {
        int index = parse_int(it->second);
        std::cout << "\nRemoving contact with index " << index << "\n";
        removed = contacts.remove_contact(index);
    }
    if(removed) std::cout << "Successfully removed\n";
    else std::cout << "Error removing\n";
}

void search_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("i");
    if(it == options.end()){
        std::cout << "\nListing all contacts\n";
        contacts.print();
        return;
    }
    int index = parse_int(it->second);

    std::cout << "\nSearching contact with index " << index << "\n";
    if (auto contact = contacts.contact(index); contact.has_value()) {
        contact.value().print();
    }
}

void bookmark_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("i");
    if(it == options.end()){
        std::cout << "\nListing bookmarked contacts\n";
        contacts.print_bookmarks();
        return;
    }
    int index = parse_int(it->second);

    std::cout << "Bookmarking contact with index " << index << "\n";
    contacts.bookmark_contact(index);
}

std::string prompt(const std::string& p) {
    std::string r {};
    std::cout << p << ">";
    getline(std::cin, r, '\n');
    return r;
}

bool jump(const std::string& select) {
    size_t whitespace = select.find(' ');
    std::string command {select};
    std::map<std::string, std::string> options;

    // Checking if there's whitespace to check for options
    if(whitespace != std::string::npos) {
        command = select.substr(0, whitespace);

        std::string options_str {select.substr(whitespace + 1, select.size())};
        std::istringstream iss(options_str);
        std::string token;

        std::string current_key;

        while (iss >> token) {
            if (token[0] == '-') {
                current_key = token.substr(1);
            } else {
                options[current_key] = token;
            }
        }
    }

    using jumpfunc = void(*)(const std::map<std::string, std::string>&);

    const std::map<std::string, jumpfunc> jumpmap {
            { "ADD", ::add_contact },
            { "SEARCH",::search_contact },
            { "REMOVE", ::remove_contact },
            { "BOOKMARK", ::bookmark_contact },
    };

    const auto it = jumpmap.find(command);
    if (it != jumpmap.end()) it->second(options);
    else {
        std::cout << "Invalid command\n";
        return false;
    }

    return true;
}

int main()
{
    std::cout << "PHONEBOOK\n";

    std::string pstr {
            "\nCommands: \nADD -n name -p phonenumber -k nickname\n"
            "SEARCH [-i <index>]\n"
            "REMOVE -i <index>/-p <phonenumber>\n"
            "BOOKMARK [-i <index>]\n"
            "EXIT\n\n"
    };

    for (auto key = prompt(pstr); key != "EXIT"; key = prompt(pstr)) {
        if (key.size() > 1) jump(key);
    }
    std::cout << "Bye!\n";

    return 0;
}
