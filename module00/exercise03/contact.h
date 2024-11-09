//
// Created by CTW03389 on 08/11/2024.
//

#ifndef SEA_ME_WARM_UP_CONTACT_H
#define SEA_ME_WARM_UP_CONTACT_H

#include <iostream>

// -- interface --
class Contact {
    std::string c_name {};
    std::string c_phone_number {};
    std::string c_nickname {};
    bool c_bookmarked {false};
public:
    Contact() = delete;
    Contact(std::string  name, std::string  phone_number, std::string  nickname);
    Contact(const Contact&); // copy constructor
    Contact(Contact&& rhs) noexcept;       // move ctor
    ~Contact() = default; // destructor
    Contact& operator = (Contact); // copy/assignment operator
    bool operator==(const Contact&) const; // equality operator
    void print() const;
    [[nodiscard]] bool bookmarked() const;
    void bookmark();
    std::string phone_number() {
        return c_phone_number;
    }
};


#endif //SEA_ME_WARM_UP_CONTACT_H
