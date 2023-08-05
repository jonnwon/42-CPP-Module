#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

/*
A();
~A();
A(const A &a);		// 복사 생성자
A &operator=(const A &a); // 복사 대입 연산자
*/

class ClapTrap
{
	protected:
		std::string m_name;
		unsigned int	m_hit_points;	 // 10
		unsigned int	m_energy_points; // 10
		unsigned int	m_attack_demage; // 0

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void			print_status();
};

#endif
