#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap() : name("unnamed"), hitPoints(10), energy(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : name(str), hitPoints(10), energy(10), attackDamage(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name), hitPoints(src.hitPoints), energy(src.energy), attackDamage(src.attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &src)
{
	if (this == &src)
		return (*this);
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	name = src.name;
	hitPoints = src.hitPoints;
	energy = src.energy;
	attackDamage = src.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cant attack because its already dead." << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " took " << amount << " damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cant repair because its already dead." << std::endl;
		return ;
	}
	if (energy <= 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy to repair itself." << std::endl;
		return ;
	}
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaired itself, recovering " << amount << " health." << std::endl;
	energy--;
}
