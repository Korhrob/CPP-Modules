
#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
};

FragTrap::FragTrap(std::string str) : ClapTrap(str, 100, 100, 30)
{
	std::cout << "FragTrap string constructor called" << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
};

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
};

void	FragTrap::takeDamage(uint amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "FragTrap " << name << " took " << amount << " damage." << std::endl;
};

void	FragTrap::beRepaired(uint amount)
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
};

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << name << " wants to high five!" << std::endl;
}