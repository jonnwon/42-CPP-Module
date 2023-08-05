#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "[FragTrap] : Constructor called, name: " << name << std::endl;
	m_hit_points = 100;
	m_energy_points = 100;
	m_attack_demage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "[FragTrap] : Copy Constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "[FragTrap] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hit_points = rhs.m_hit_points;
		m_energy_points = rhs.m_energy_points;
		m_attack_demage = rhs.m_attack_demage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] : Destructor called, name: " << m_name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (m_hit_points == 0)
	{
		std::cout << "FragTrap " << m_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (m_energy_points == 0)
	{
		std::cout << "FragTrap " << m_name << " has no energy points!" << std::endl;
		return ;
	}
		std::cout << "FragTrap " << m_name << " request a positive high fives!" << std::endl;

}
