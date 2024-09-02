#include "Harl.hpp"
#include <iostream>
#include <string>

int Harl::filterLevel = 0;

void Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
	int	flag = 0;

	for (int i = 0; i < 4; i++)
	{
		if (level == levelHandle[i]) // change filter level from int to string(?)
		{
			flag = 1;
			if (i >= filterLevel)
				(this->*funcHandle[i])();
		}
	}
	if (!flag)
		std::cout << "Unknown level: " << level << std::endl;
}

void Harl::setFilterLevel(int i)
{
	Harl::filterLevel = i;
}

std::string Harl::getFilterLevel(int i)
{
	return levelHandle[i];
}
