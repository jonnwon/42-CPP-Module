/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:28 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/20 19:15:47 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string cmd;

	std::cout << "An empty phonebook has been created!" << std::endl;
	std::cout << "Enter one of ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << "Please select an action: (ADD, SEARCH, EXIT) " << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
		{
			std::cout << "Contact deleted!" << std::endl;
			break ;
		}
//		else if (cmd.compare("ADD"))
			
//		std::cout << cmd << std::endl;
	}

	return (0);
}
