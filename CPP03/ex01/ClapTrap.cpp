
#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string str, unsigned int hitPoints, unsigned int energy, unsigned int attackDamage) : name(str), hitPoints(hitPoints), energy(energy), attackDamage(attackDamage)
{
	std::cout << "ClapTrap constructor called" << std::endl;
};


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
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
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energy--;
};

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " took " << amount << " damage." << std::endl;
};

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
};
