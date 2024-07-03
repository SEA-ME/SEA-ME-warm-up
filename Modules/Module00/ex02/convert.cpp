/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allisonmartinez <allisonmartinez@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:03:36 by allisonmart       #+#    #+#             */
/*   Updated: 2024/07/03 13:52:00 by allisonmart      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ConvertString(std::string str, int acase)
{
	int	i = 0;
	while(str[i])
	{
		if (acase == 1)
			std::cout << (char)toupper(str[i]);
		if (acase == -1)
			std::cout << (char)tolower(str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "Please Enter Arguments\n";
	else
	{
		std::string input1 (argv[1]);
		int	i = 2;
		while(argv[i])
		{
			std::string input(argv[i]);
			if (input1.compare("up") == 0)
				ConvertString(input, 1);
			else if (input1.compare("down") == 0)
				ConvertString(input, -1);
			else
			{
				std::cout << "Please enter \"up\" or \"down\"";
				break ;
			}
			std::cout << " ";
			i++;
		}
		std::cout << '\n';
	}
	return (0);
}