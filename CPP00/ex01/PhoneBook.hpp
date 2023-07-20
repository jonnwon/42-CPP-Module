#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

/*
addContact
searchContact
removeConctact
printAllContacnt

*/

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


		//	void	removeContact();
		//	void	printAallContact();
		void	print_contact(int index);

};

#endif
