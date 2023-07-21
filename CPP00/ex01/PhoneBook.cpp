#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { this->index = 0; }
PhoneBook::~PhoneBook() { }

void	PhoneBook::addContact()
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

void	PhoneBook::print_contact(int index)
{
	std::string str;

	std::cout << std::setw(10) << index + 1;
	std::cout << "|";

	str =  contact[index].get_firstName();
	std::cout << std::setw(10) << str;
	std::cout << "|";

	str =  contact[index].get_lastName();
	std::cout << std::setw(10) << str;
	std::cout << "|";

	str =  contact[index].get_nickName();
	std::cout << std::setw(10) << str;
	std::cout << "|" << std::endl;

}

void	PhoneBook::searchContact()
{
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

	int i = 0;
	while (i < 8) //&& contact[i].get_firstName().compare("") != 0)
	{
		PhoneBook::print_contact(i);
		std::cout << "--------------------------------------------"<< std::endl;
		i++;
	}
}


