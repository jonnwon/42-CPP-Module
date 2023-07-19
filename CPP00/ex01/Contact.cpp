#include "PhoneBook.hpp"

Contact::Contact() { }
Contact::~Contact() { }

void	Contact::setFirstName(std::string str) { this->firstName = str; }
void	Contact::set_lastName(std::string str) { this->lastName = str; }
void	Contact::set_nickName(std::string str) { this->nickName = str; }
void	Contact::set_phoneName(std::string str) { this->phoneName = str; }
void	Contact::set_darkestSecret(std::string str)	{ this->darkestSecret = str; }


std::string	Contact::get_firstName(void) { return (this->firstName); }
std::string	Contact::get_lastName(void) { return (this->lastName); }
std::string	Contact::get_nickName(void) { return (this->nickName); }
std::string	Contact::get_phoneName(void) { return (this->phoneName); }
std::string	Contact::get_darkestSecret(void) { return (this->darkestSecret); }

void	Contact::set_contact(Contact contact) {
	this->firstName = contact.firstName;
	this->lastName = contact.lastName;
	this->nickName = contact.nickName;
	this->phoneName = contact.phoneName;
	this->darkestSecret = contact.darkestSecret;
}
