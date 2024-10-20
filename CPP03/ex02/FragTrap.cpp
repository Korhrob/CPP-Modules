#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap("unnamed", 100, 50, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& str) : ClapTrap(str, 100, 50, 30)
{
	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &src)
{
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "FragTrap " << name << " cant attack because its already dead." << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "FragTrap " << name << " doesn't have enough energy to attack." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energy--;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "FragTrap " << name << " took " << amount << " damage." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "FragTrap " << name << " cant repair because its already dead." << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "FragTrap " << name << " doesn't have enough energy to repair itself." << std::endl;
		return ;
	}
	hitPoints += amount;
	std::cout << "FragTrap " << name << " repaired itself, recovering " << amount << " health." << std::endl;
	energy--;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << name << " wants to high five!" << std::endl;
}
