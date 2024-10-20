#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);

	return (zombie);
}
