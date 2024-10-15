
#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string str) : name(str)
{
	std::cout << "String constructor called" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
};

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
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << "points of damage!" << std::endl;
	energy--;
};

void	ClapTrap::takeDamage(uint amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " took " << amount << " damage." << std::endl;
};

void	ClapTrap::beRepaired(uint amount)
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
};
