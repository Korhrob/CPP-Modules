#include "Zombie.hpp"
#include <iostream>
#include <string>

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "delete " << this->name << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
