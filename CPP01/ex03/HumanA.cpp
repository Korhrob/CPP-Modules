#include "HumanA.hpp"
#include <iostream>
#include <string>
#include <optional>

void HumanA::attack()
{
	if (weapon.getType().empty())
		std::cout << name << "attacks with their bare fists" << std::endl;
	else
		std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA()
{
}
