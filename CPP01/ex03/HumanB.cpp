#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string& name) : name(name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (weapon.getType().empty())
		std::cout << name << "attacks with their bare fists" << std::endl;
	else
		std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}
