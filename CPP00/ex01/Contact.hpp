#ifndef CONTACT_HPP
#define CONTACT_HPP

/*
index | first name | last name | nickname 

 first name, last name, nickname, phone number, and
darkest secret.
*/

class Contact {
 private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

 public:
	Contact();
	~Contact();

	void set_firstName(std::string str);
	void set_lastName(std::string str);
	void set_nickName(std::string str);
	void set_phoneNumber(std::string str);
	void set_darkestSecret(std::string str);

	std::string get_firstName(void);
	std::string get_lastName(void);
	std::string get_nickName(void);
	std::string get_phoneNumber(void);
	std::string get_darkestSecret(void);

	void set_contact(Contact contact);
//	void print_contact(void);
};

#endif
