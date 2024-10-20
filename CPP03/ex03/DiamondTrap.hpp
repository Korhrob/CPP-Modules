#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string.h>

class DiamongTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;

	public:
		DiamongTrap();
		DiamongTrap(const std::string& name);
		DiamongTrap(const DiamongTrap &copy);
		DiamongTrap& operator= (const DiamongTrap& copy);
		~DiamongTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
