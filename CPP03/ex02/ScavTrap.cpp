#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("unnamed", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& str) : ClapTrap(str, 100, 50, 20)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cant attack because its already dead." << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "ScavTrap " << name << " doesn't have enough energy to attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energy--;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ScavTrap " << name << " took " << amount << " damage." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cant repair because its already dead." << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "ScavTrap " << name << " doesn't have enough energy to repair itself." << std::endl;
		return ;
	}
	hitPoints += amount;
	std::cout << "ScavTrap " << name << " repaired itself, recovering " << amount << " health." << std::endl;
	energy--;
}

void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << name << " is in gate keeper mode." << std::endl;
}
