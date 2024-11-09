//
// Created by CTW03389 on 08/11/2024.
//

#include "phonebook.h"
#include <algorithm>
#include <iterator>

// initializer-list ctor
Phonebook::Phonebook(std::initializer_list<Contact> il) : contacts {il.begin(), il.end()} {
    //std::cout << "phonebook initializer-list ctor\n";
}

void Phonebook::add_contact(Contact &contact) {
    auto it = std::find(contacts.begin(), contacts.end(), contact);
    if(it != contacts.end()) {
        std::cout << "Contact already exists in phonebook\n";
        return;
    }
    contacts.emplace_back(contact);
    std::cout << "Contact added\n";
}

void Phonebook::print() const {
    if(contacts.empty()) {
        std::cout << "No contacts\n";
        return;
    }
    for(const Contact& i : contacts) i.print();
}

void Phonebook::print_bookmarks() const {
    std::vector<Contact> bookmarks;
    std::copy_if(contacts.begin(), contacts.end(), std::back_inserter(bookmarks),
                 [](const Contact& x) { return x.bookmarked(); });

    if(bookmarks.empty()) {
        std::cout << "No bookmarks\n";
        return;
    }
    for(const Contact& i : bookmarks) i.print();
}

std::optional<Contact> Phonebook::contact(int index) {
    if (auto it = contact_it(index); it.has_value()) {
        return *it.value();
    }
    return {};
}

std::optional<std::vector<Contact>::iterator> Phonebook::contact_it(int index) {
    if(index < 0 || index > contacts.size() -1) {
        std::cout << "Index out of bounds\n";
        return {};
    }
    return contacts.begin() + index;
}

void Phonebook::bookmark_contact(int index) {
    if (auto it = contact_it(index); it.has_value()) {
        it.value()->bookmark();
    }
}

bool Phonebook::remove_contact(const std::string& phone_number) {
    auto c_it = std::find_if(contacts.begin(), contacts.end(),
                        [phone_number](Contact& c) {return c.phone_number() == phone_number;});
    if(c_it != contacts.end()) {
        int index = static_cast<int>(distance(contacts.begin(), c_it));
        return remove_contact(index);
    } else {
        return false;
    }
}

bool Phonebook::remove_contact(int index) {
    if (auto it = contact_it(index); it.has_value()) {
        contacts.erase(it.value());
        return true;
    }
    return false;
}
