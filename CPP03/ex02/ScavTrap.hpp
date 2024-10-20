#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	private:

	public:

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void	attack(const std::string& target) override;
		void	takeDamage(uint amount) override;
		void	beRepaired(uint amount) override;
		void	guardGate() const;

}