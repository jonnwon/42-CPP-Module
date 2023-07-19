#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.h"

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNum;
    std::string darkestSecret;
public:
    Contact();
    ~Contact();

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickName(std::string nickName);
    void setPhoneNum(std::string phoneNum);
    void setDarkestSecret(std::string darkestSecret);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNum();
    std::string getDarkestSecret();

    void setAllInfo(Contact contact);
};

#endif
