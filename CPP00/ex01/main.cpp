/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:57:20 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/22 01:35:21 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	PhoneBook phonebook;

	std::cout << "An empty phonebook has been created!" << std::endl;
	std::cout << "Enter one of ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << "Please select an action: (ADD, SEARCH, EXIT) " << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0 || std::cin.eof())
		{
			std::cout << "Contact deleted!" << std::endl;
			break ;
		}
		else if (cmd.compare("ADD") == 0)
			phonebook.addContact();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.searchContact();
			
//		std::cout << cmd << std::endl;
	}

	return (0);
}
