/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allisonmartinez <allisonmartinez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:18:24 by amartine          #+#    #+#             */
/*   Updated: 2024/07/03 13:54:35 by allisonmart      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Search User input for commands: ADD, SEARCH, REMOVE, BOOKMARK, EXIT
// Each instance of a new contact should include: NAME, PHONE NUMBER, NICKNAME and an INDEX
// Then it should be added to a "Phonebook" list
#include "Phonebook.h"

void	AddContact()
{
	Contact person;
	std::string name;
	std::string phone_number;
	std::string nickname;

	std::cout <<"Name: ";
	std::getline(std::cin, name);
	person.setName(name);

	std::cout <<"Phone Number: ";
	std::getline(std::cin, phone_number);
	person.setPhoneNumber(phone_number);

	std::cout <<"Nickname: ";
	std::getline(std::cin, nickname);
	person.setNickname(nickname);
}

int main(int argc, char *argv[])
{
	if (argc < 1)
		std::cout << "Please Enter One of the Following: ADD, SEARCH, REMOVE, BOOKMARK, or EXIT";
	else
	{
		std::string input1 (argv[1]);
		if (input1.compare("ADD") == 0)
			AddContact();
	}
}
