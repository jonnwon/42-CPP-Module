#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap()
:ClapTrap("defalut_clap_name"), m_name("defalut")
{
	std::cout << "[DiamondTrap] : Defalut constructor called, name: " << m_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name"), m_name(name)
{
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_demage = 30;
	std::cout << "[DiamondTrap] : Defalut constructor called, name: " << m_name << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& other)
:ClapTrap(other.ClapTrap::m_name)
{
	std::cout << "[DiamondTrap] : Copy Constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "[DiamondTrap] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::m_name = rhs.ClapTrap::m_name;
		m_name = rhs.m_name;
		m_hit_points = rhs.m_hit_points;
		m_energy_points = rhs.m_energy_points;
		m_attack_demage = rhs.m_attack_demage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] : Destructor called, name: " << m_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] : whoAmI called" << std::endl;
	std::cout << "DiamondTrap name : " << m_name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::m_name << std::endl;
}








