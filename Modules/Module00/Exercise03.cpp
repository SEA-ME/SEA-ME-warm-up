#include <iostream>   // For input and output operations
#include <string>     // For using std::string
#include <vector>     // For using std::vector
#include <algorithm>  // For using std::find_if

// Class representing a contact in the phonebook
class Contact {
public:
    std::string name;     // Contact's name
    long long PhoneNum;   // Contact's phone number (unique)
    std::string Nickname; // Contact's nickname

public:
    // Constructor to initialize contact details
    Contact(const std::string& n = "", long long PN = 0, const std::string& Nn = "")
        : name(n), PhoneNum(PN), Nickname(Nn) {}

    // Setter function to update contact details
    void setContactInfo(const std::string& n, long long PN, const std::string& Nn) {
        name = n;
        PhoneNum = PN;
        Nickname = Nn;
    }

    // Getter function to retrieve contact details
    Contact getContactInfo() const {
        return {name, PhoneNum, Nickname};
    }
};

// Class representing a phonebook
class PhoneBook {
public:
    std::vector<Contact> Contacts;          // List of all contacts
    std::vector<Contact> BookmarkedContacts; // List of bookmarked contacts

public:
    // Function to add a new contact to the phonebook
    void Add(const std::string& name, long long PN, const std::string& Nn) {
        Contacts.emplace_back(name, PN, Nn); // Add new contact to Contacts vector
    }

    // Function to search and display contacts
    void Search() {
        size_t tempval = 0;

        std::cout << "The list of contacts is: " << std::endl;
        std::cout << "Index: " << std::endl;
        for (size_t i = 0; i < Contacts.size(); i++) {
            std::cout << i << ": " << Contacts[i].name << std::endl; // Display index and name of each contact
        }

        size_t index;
        std::cout << "Enter index to view details: ";
        std::cin >> index; // Get index from user
        
        displayContactDetails(index); // Display details of the selected contact

        if (index < Contacts.size()) {
            char bookmark;
            std::cout << "Bookmark it? Y/N" << std::endl;
            std::cin >> bookmark; // Get user's choice for bookmarking

            if (bookmark == 'Y' || bookmark == 'y') {
                Bookmark(index); // Add contact to bookmarks
                displayBookmarkedContacts(); // Display bookmarked contacts
            }
            std::cout << "Size of bookmarked list is: " << BookmarkedContacts.size() << std::endl;
        }
    }

    // Function to display details of a contact
    void displayContactDetails(size_t index) {
        if (index < Contacts.size()) {
            std::cout << "Name:         " << Contacts[index].name << std::endl;
            std::cout << "Phone Number: 0" << Contacts[index].PhoneNum << std::endl;
            std::cout << "Nickname:     " << Contacts[index].Nickname << std::endl;
        } else {
            std::cout << "Index not valid" << std::endl; // Error message for invalid index
        }
    }

    // Function to display all bookmarked contacts
    void displayBookmarkedContacts() {
        if (BookmarkedContacts.empty()) {
            std::cout << "The Bookmarked list is empty!" << std::endl; // Message when no bookmarks are present
        } else {
            std::cout << "The Bookmarked list: " << std::endl;
            for (size_t i = 0; i < BookmarkedContacts.size(); i++) {
                std::cout << "Name:         " << BookmarkedContacts[i].name << std::endl;
                std::cout << "Phone Number: 0" << BookmarkedContacts[i].PhoneNum << std::endl;
                std::cout << "Nickname:     " << BookmarkedContacts[i].Nickname << std::endl;
            }
        }
    }

    // Function to bookmark a contact by index
    void Bookmark(size_t index) {
        BookmarkedContacts.push_back(Contacts[index]); // Add contact to BookmarkedContacts vector
        std::cout << "The Contact " << Contacts[index].name << " was bookmarked successfully" << std::endl;  
    }

    // Function to remove a contact by index or phone number
    void Remove() {
        char choice;
        std::cout << "Remove by (i)ndex or (p)hone number? ";
        std::cin >> choice; // Get user choice for removal

        if (choice == 'i' || choice == 'I') {
            size_t index;
            std::cout << "Enter index: ";
            std::cin >> index; // Get index from user

            if (index < Contacts.size()) {
                Contacts.erase(Contacts.begin() + index); // Remove contact from Contacts vector
                BookmarkedContacts.erase(std::remove_if(BookmarkedContacts.begin(), BookmarkedContacts.end(),
                    [index, this](const Contact& c) {
                        return c.PhoneNum == Contacts[index].PhoneNum; // Remove from bookmarks if present
                    }), BookmarkedContacts.end());
                std::cout << "Contact removed." << std::endl;
            } else {
                std::cout << "Invalid index." << std::endl; // Error message for invalid index
            }
        } else if (choice == 'p' || choice == 'P') {
            long long phoneNumber;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber; // Get phone number from user

            auto it = std::find_if(Contacts.begin(), Contacts.end(), [phoneNumber](const Contact& c) {
                return c.PhoneNum == phoneNumber; // Find contact by phone number
            });

            if (it != Contacts.end()) { // Check if contact is found
                Contacts.erase(it); // Remove contact from Contacts vector
                BookmarkedContacts.erase(std::remove_if(BookmarkedContacts.begin(), BookmarkedContacts.end(),
                    [phoneNumber](const Contact& c) {
                        return c.PhoneNum == phoneNumber; // Remove from bookmarks if present
                    }), BookmarkedContacts.end());
                std::cout << "Contact removed." << std::endl;
            } else {
                std::cout << "Phone number not found." << std::endl; // Error message if phone number is not found
            }
        } else {
            std::cout << "Invalid choice." << std::endl; // Error message for invalid choice
        }
    }
};

// Main function to execute the program
int main() {
    PhoneBook phoneBook; // Create an instance of PhoneBook
    std::string command;

    // Main loop to process user commands
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        std::cin >> command; // Get command from user

        if (command == "ADD" || command == "add") {
            std::string name, nickname;
            long long phoneNumber;
            std::cout << "Enter name: ";
            std::cin >> name; // Get name from user
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber; // Get phone number from user
            std::cout << "Enter nickname: ";
            std::cin >> nickname; // Get nickname from user
            phoneBook.Add(name, phoneNumber, nickname); // Add new contact
        } else if (command == "SEARCH" || command == "search") {
            phoneBook.Search(); // Search and display contacts
        } else if (command == "REMOVE" || command == "remove") {
            phoneBook.Remove(); // Remove a contact
        } else if (command == "BOOKMARK" || command == "bookmark") {
            phoneBook.displayBookmarkedContacts(); // Display bookmarked contacts
        } else if (command == "EXIT" || command == "exit") {
            break; // Exit the loop and end the program
        } else {
            std::cout << "Unknown command. Please try again." << std::endl; // Error message for unknown command
        }
    }
    return 0; // Return 0 to indicate successful program execution
}
