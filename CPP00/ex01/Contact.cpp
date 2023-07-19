#include "Contact.hpp"

Contact::Contact() { }
Contact::~Contact() { }

void Contact::setFirstName(std::string firstName) { this->firstName = firstName; }
void Contact::setLastName(std::string lastName) {  this->lastName = lastName; }
void Contact::setNickName(std::string nickName) { this->nickName = nickName; }
void Contact::setPhoneNum(std::string phoneNum) { this->phoneNum = phoneNum; }
void Contact::setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }

std::string Contact::getFirstName() { return this->firstName; }
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickName() { return this->nickName; }
std::string Contact::getPhoneNum() { return this->phoneNum; }
std::string Contact::getDarkestSecret() { return this->darkestSecret; }

void Contact::setAllInfo(Contact contact) {
    this->firstName = contact.firstName;
    this->lastName = contact.lastName;
    this->nickName = contact.nickName;
    this->phoneNum = contact.phoneNum;
    this->darkestSecret = contact.darkestSecret;
}
