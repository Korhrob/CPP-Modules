#include "Zombie.hpp"
#include <iostream>

void	randomChump(const std::string& name)
{
	Zombie chump(name);

	chump.announce();
}
