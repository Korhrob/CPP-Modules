#include "Harl.hpp"
#include <iostream>
#include <string>

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
	for (int i = 0; i < 4; i++)
	{
		if (level == levelHandle[i])
		{
			(this->*funcHandle[i])();
			return;
		}
	}
	std::cout << "Unknown level: " << level << std::endl;
}
