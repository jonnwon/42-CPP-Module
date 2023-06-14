/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:28 by jonchoi           #+#    #+#             */
/*   Updated: 2023/06/14 16:08:01 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string cmd;

	while (1)
	{
		std::cout << "input> ";
		std::getline(std::cin, cmd);
		if (cmd == "")
			break ;

		std::cout << cmd << std::endl;
	}

	return (0);
}
