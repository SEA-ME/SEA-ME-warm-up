//
// Created by CTW03389 on 08/11/2024.
//

#include "contact.h"

#include <utility>

Contact::Contact(std::string  name, std::string  phone_number, std::string  nickname)
        : c_name(std::move(name)), c_phone_number(std::move(phone_number)), c_nickname(std::move(nickname)){
    //std::cout << "contact ctor " << c_name << "\n";
}

// Copy ctor
Contact::Contact(const Contact& c): c_name(c.c_name), c_nickname(c.c_nickname),
c_phone_number(c.c_phone_number), c_bookmarked(c.c_bookmarked) {
    //std::cout << "contact copy ctor " << c_name << "\n";
}

// move ctor
Contact::Contact(Contact&& rhs) noexcept
        : c_name {std::move(rhs.c_name)}, c_phone_number {std::move(rhs.c_phone_number)},
        c_nickname {std::move(rhs.c_nickname)}, c_bookmarked {rhs.c_bookmarked} {
    //std::cout << "contact move ctor " << c_name << "\n";
}

bool Contact::operator==(const Contact& o) const {
    return c_phone_number == o.c_phone_number;
}

// Operator overloading = just so the object doesn't copy itself
Contact& Contact::operator = (Contact rhs) {
    //std::cout << "contact copy/swap operator\n";
    std::swap(c_name, rhs.c_name);
    std::swap(c_phone_number, rhs.c_phone_number);
    std::swap(c_nickname, rhs.c_nickname);
    std::swap(c_bookmarked, rhs.c_bookmarked);
    return *this;
}

void Contact::print () const {
    std::cout << "* Contact " << c_name << "(" << c_nickname << ") w phone " << c_phone_number << " " << (c_bookmarked ? "x": "o") << "\n";
}

bool Contact::bookmarked() const {
    return c_bookmarked;
}

void Contact::bookmark() {
    c_bookmarked = !c_bookmarked;
}
