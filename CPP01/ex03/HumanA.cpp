#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	if (weapon.getType().empty())
		std::cout << name << "attacks with their bare fists" << std::endl;
	else
		std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}
