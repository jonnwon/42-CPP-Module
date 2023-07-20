#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

/*
addContact
searchContact
removeConctact
printAllContacnt

*/

class PhoneBook {
 private:
	Contact	contact[8];
	int		size;

 public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
//	void	searchContact();
//	void	removeContact();
//	void	printAallContact();

};

#endif
