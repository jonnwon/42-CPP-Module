#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:m_name("defalut"), m_hit_points(10), m_energy_points(10), m_attack_demage(0)
{
	std::cout << "Defualt construcor called, name: defalut" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:m_name(name), m_hit_points(10), m_energy_points(10), m_attack_demage(0)
{
	std::cout << "Constructor called, name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hit_points = rhs.m_hit_points;
		m_energy_points = rhs.m_energy_points;
		m_attack_demage = rhs.m_attack_demage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (m_hit_points == 0)
	{
		std::cout << "ClapTrap " << m_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (m_energy_points == 0)
	{
		std::cout << "ClapTrap " << m_name << " has no energy points!" << std::endl;
		return ;
	}
//ClapTrap <name> attacks <target>, causing <damage> points of damage!
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_demage << " points of damage!" << std::endl;
	m_energy_points--;
	print_status();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage!" << std::endl;
	if (m_hit_points <= amount)
		m_hit_points = 0;
	else
		m_hit_points -= amount;
	print_status();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_hit_points == 0)
	{
		std::cout << "ClapTrap " << m_name << " has no hit points!" << std::endl;
		return ;
	}
	else if (m_energy_points == 0)
	{
		std::cout << "ClapTrap " << m_name << " has no energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << m_name << " was repaired by " << amount << " hitpoints!" << std::endl;
	m_hit_points += amount;
	m_energy_points--;
	print_status();
}

void	ClapTrap::print_status()
{
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "name: " << m_name << std::endl;
	std::cout << "hit points: " << m_hit_points << std::endl;
	std::cout << "energy points: " << m_energy_points << std::endl;
	std::cout << "attack_demage: " << m_attack_demage << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;
}
