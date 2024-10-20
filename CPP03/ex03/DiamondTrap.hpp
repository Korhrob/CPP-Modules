#include "ClapTrap.hpp"
#include <string.h>

class DiamongTrap : public FragTrap, public ScavTrap
{

	private:
		std::string	name;

	public:

		DiamongTrap();
		DiamongTrap(std::string name);
		~DiamongTrap();

		void	attack(const std::string& target) override;
		void	takeDamage(uint amount) override;
		void	beRepaired(uint amount) override;

}