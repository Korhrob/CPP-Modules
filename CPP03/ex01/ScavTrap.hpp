#include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{

	private:

	public:

		ScavTrap();
		ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {}
		~ScavTrap();

		void	attack(const std::string& target) override;
		void	takeDamage(uint amount) override;
		void	beRepaired(uint amount) override;
		void	guardGate();

}