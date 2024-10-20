#pragma once

#include <string>

class	ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energy;
		unsigned int	attackDamage;
		ClapTrap(const std::string& name, unsigned int hp, unsigned int e, unsigned int ad);

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator= (const ClapTrap& copy);
		~ClapTrap();

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
};
