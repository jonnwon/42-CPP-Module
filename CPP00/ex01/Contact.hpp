/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:12:04 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/19 01:58:55 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::string phoneName;
	std::string darkestSecret;

 public:
	Contact();
	~Contact();

	void set_firstName(std::string str);
	void set_lastName(std::string str);
	void set_nickName(std::string str);
	void set_phoneName(std::string str);
	void set_darkestSecret(std::string str);

	std::string get_firstName(void);
	std::string get_lastName(void);
	std::string get_nickName(void);
	std::string get_phoneName(void);
	std::string get_darkestSecret(void);

	void set_contact(Contact contact);
};

#endif
