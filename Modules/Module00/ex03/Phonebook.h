/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allisonmartinez <allisonmartinez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 07:10:07 by allisonmart       #+#    #+#             */
/*   Updated: 2024/07/03 13:56:07 by allisonmart      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

class Contact {
public:
	// Constructors
	Contact();
	Contact(std::string name, std::string phone_number, std::string nickname);

	// Setters
	void setName(std::string name);
	void setPhoneNumber(std::string phone_number);
	void setNickname(std::string nickname);

	// Getters
	std::string getName() const;
	std::string getPhoneNumber() const;
	std::string getNickname() const;

private:
	std::string Name;
	std::string PhoneNumber;
	std::string Nickname;
};
#endif