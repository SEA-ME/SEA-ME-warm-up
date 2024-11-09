//
// Created by CTW03389 on 08/11/2024.
//

#ifndef SEA_ME_WARM_UP_PHONEBOOK_H
#define SEA_ME_WARM_UP_PHONEBOOK_H

#include "contact.h"
#include <vector>
#include <set>
#include <optional>

class Phonebook  {
    std::vector<Contact> contacts {};
    std::optional<std::vector<Contact>::iterator> contact_it(int index);
public:
    Phonebook() = default;   // default ctor
    Phonebook(std::initializer_list<Contact> il);    // il ctor
    void print() const;
    void print_bookmarks() const;
    void add_contact(Contact& contact);
    bool remove_contact(int index);
    bool remove_contact(const std::string& phone_number);
    void bookmark_contact(int index);
    std::optional<Contact> contact(int index);
};


#endif //SEA_ME_WARM_UP_PHONEBOOK_H
