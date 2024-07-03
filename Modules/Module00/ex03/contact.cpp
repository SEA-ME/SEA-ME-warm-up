/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allisonmartinez <allisonmartinez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 07:46:35 by allisonmart       #+#    #+#             */
/*   Updated: 2024/07/03 13:55:47 by allisonmart      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.h"

// Constructors
Contact::Contact() : Name(""), PhoneNumber(""), Nickname("") {}

Contact::Contact(std::string name, std::string phone_number, std::string nickname)
	: Name(name), PhoneNumber(phone_number), Nickname(nickname) {}

// Setters
void Contact::setName(std::string name) {
	Name = name;
}

void Contact::setPhoneNumber(std::string phone_number) {
	PhoneNumber = phone_number;
}

void Contact::setNickname(std::string nickname) {
	Nickname = nickname;
}

// Getters
std::string Contact::getName() const {
	return Name;
}

std::string Contact::getPhoneNumber() const {
	return PhoneNumber;
}

std::string Contact::getNickname() const {
	return Nickname;
}
