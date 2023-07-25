/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 04:53:56 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/23 05:06:51 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
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
};

#endif
