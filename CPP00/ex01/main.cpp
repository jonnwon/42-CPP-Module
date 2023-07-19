/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:28 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/18 20:07:52 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string cmd;

	while (1)
	{
		std::cout << "input> ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
		{
			std::cout << "QUIT" << std::endl;
			break ;
		}

		std::cout << cmd << std::endl;
	}

	return (0);
}
