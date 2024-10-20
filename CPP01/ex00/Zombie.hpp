#pragma once

#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(const std::string& name);
		~Zombie();

		void	announce(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
