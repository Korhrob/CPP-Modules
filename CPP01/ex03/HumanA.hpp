#pragma once

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
	std::string	name;
	Weapon		weapon;

	public:
	void	attack();
	HumanA(std::string name, Weapon weapon);
	~HumanA();

};