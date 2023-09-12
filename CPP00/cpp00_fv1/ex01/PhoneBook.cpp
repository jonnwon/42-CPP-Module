/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 04:54:04 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/22 05:03:46 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { this->index = 0; }
PhoneBook::~PhoneBook() { }

void	PhoneBook::addContact(void)
{
	std::string str;

	if (this->index > 7)
		this->index = 0;

	std::cout << "Please enter first name" << std::endl;
	std::getline(std::cin, str);
	contact[this->index].set_firstName(str);

	std::cout << "Please enter last name" << std::endl;
	std::getline(std::cin, str);
	contact[this->index].set_lastName(str);

	std::cout << "Please enter nickname" << std::endl;
	std::getline(std::cin, str);
	contact[this->index].set_nickName(str);

	std::cout << "Please enter phone number" << std::endl;
	std::getline(std::cin, str);
	contact[this->index].set_phoneNumber(str);

	std::cout << "Please enter darkest secret" << std::endl;
	std::getline(std::cin, str);
	contact[this->index].set_darkestSecret(str);

	this->index++;	
}

void	PhoneBook::print_name(int index)
{
	std::string str;

	std::cout << std::setw(10) << index + 1;
	std::cout << "|";

	str =  contact[index].get_firstName();
	if (str.length() >= 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str;
	std::cout << "|";

	str =  contact[index].get_lastName();
	if (str.length() >= 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str;
	std::cout << "|";

	str =  contact[index].get_nickName();
	if (str.length() >= 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str;
	std::cout << "|" << std::endl;
}

void	PhoneBook::print_contact(std::string index)
{
	int idx;

	idx = index[0] - '0';
	std::cout << "first name : " << contact[idx - 1].get_firstName() << std::endl; 
	std::cout << "last name : " << contact[idx - 1].get_lastName() << std::endl; 
	std::cout << "nick name : " << contact[idx - 1].get_nickName() << std::endl; 
	std::cout << "phone number : " << contact[idx - 1].get_phoneNumber() << std::endl; 
	std::cout << "darkest secret : " << contact[idx - 1].get_darkestSecret() << std::endl; 
}

void	PhoneBook::searchContact(void)
{
	int i;

	std::cout << "============================================"<< std::endl;
	std::cout << std::setw(10) << "index";
	std::cout << "|";

	std::cout << std::setw(10) << "firstName";
	std::cout << "|";

	std::cout << std::setw(10) << "lastName";
	std::cout << "|";

	std::cout << std::setw(10) << "nickName";
	std::cout << "|";
	std::cout << std::endl;
	std::cout << "============================================"<< std::endl;

	i = 0;
	while (i < 8)
	{
		PhoneBook::print_name(i);
		std::cout << "--------------------------------------------"<< std::endl;
		i++;
	}

	std::string index;
	std::cout << "Please enter the index you are looking for." << std::endl;
	std::getline(std::cin, index);

	if (index.compare("1") == 0)
		print_contact(index);
	else if (index.compare("2") == 0)
		print_contact(index);
	else if (index.compare("3") == 0)
		print_contact(index);
	else if (index.compare("4") == 0)
		print_contact(index);
	else if (index.compare("5") == 0)
		print_contact(index);
	else if (index.compare("6") == 0)
		print_contact(index);
	else if (index.compare("7") == 0)
		print_contact(index);
	else if (index.compare("8") == 0)
		print_contact(index);
	else
		std::cout << "warning: Invalid index" << std::endl;
}
