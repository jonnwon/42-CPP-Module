#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		int		index;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
		void	print_name(int index);
		void	print_contact(std::string index);
};

#endif
