#include "PhoneBook.hpp"

Contact::Contact() { }
Contact::~Contact() { }

void	Contact::set_firstName(std::string str) { this->firstName = str; }
void	Contact::set_lastName(std::string str) { this->lastName = str; }
void	Contact::set_nickName(std::string str) { this->nickName = str; }
void	Contact::set_phoneNumber(std::string str) { this->phoneNumber = str; }
void	Contact::set_darkestSecret(std::string str)	{ this->darkestSecret = str; }

std::string	Contact::get_firstName(void) { return (this->firstName); }
std::string	Contact::get_lastName(void) { return (this->lastName); }
std::string	Contact::get_nickName(void) { return (this->nickName); }
std::string	Contact::get_phoneNumber(void) { return (this->phoneNumber); }
std::string	Contact::get_darkestSecret(void) { return (this->darkestSecret); }
