#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "[ScavTrap] : Constructor called, name: " << name << std::endl;
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_demage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "[ScavTrap] : Copy Constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "[ScavTrap] : Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hit_points = rhs.m_hit_points;
		m_energy_points = rhs.m_energy_points;
		m_attack_demage = rhs.m_attack_demage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] : Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (m_hit_points == 0)
	{
		std::cout << "ScavTrap " << m_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (m_energy_points == 0)
	{
		std::cout << "ScavTrap " << m_name << " has no energy points!" << std::endl;
		return ;
	}
//ScavTrap <name> attacks <target>, causing <damage> points of damage!
	std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attack_demage << " points of damage!" << std::endl;
	m_energy_points--;
	print_status();
}

void ScavTrap::guardGate()
{
	if (m_hit_points == 0)
	{
		std::cout << "ScavTrap " << m_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (m_energy_points == 0)
	{
		std::cout << "ScavTrap " << m_name << " has no energy points!" << std::endl;
		return ;
	}
		std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode" << std::endl;
}
