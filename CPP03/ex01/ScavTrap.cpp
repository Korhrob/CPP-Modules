
#include <string>
#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
};

ScavTrap::ScavTrap(std::string str) : name(str)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
};

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
};

void	ScavTrap::takeDamage(uint amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ScavTrap " << name << " took " << amount << " damage." << std::endl;
};

void	ScavTrap::beRepaired(uint amount)
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
};

void	ScavTrap::