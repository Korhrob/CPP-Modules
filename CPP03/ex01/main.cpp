#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	ClapTrap clapTrap = ClapTrap("Bob");
	ScavTrap scavTrap = ScavTrap("John");

	scavTrap.guardGate();
	clapTrap.attack("John");
	scavTrap.takeDamage(0);
	scavTrap.beRepaired(0);
	scavTrap.attack("Bob");
	clapTrap.takeDamage(20);

	return 0;
}
