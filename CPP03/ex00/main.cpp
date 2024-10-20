#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int	main()
{
	ClapTrap a = ClapTrap("alpha");
	ClapTrap b = ClapTrap("beta");

	ClapTrap a_cpy = ClapTrap(a);
	ClapTrap b_cpy;
	b_cpy = b;

	a.attack("b");
	b.takeDamage(1);
	b.attack("something");
	a.takeDamage(1);
	b.beRepaired(1);
	b.attack("something");
	a.takeDamage(999);
	a.attack("b");

	return 0;
}
