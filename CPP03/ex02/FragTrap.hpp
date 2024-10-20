#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	private:

	public:

		FragTrap();
		FragTrap(std::string name);
		~FragTrap();

		void	attack(const std::string& target) override;
		void	takeDamage(uint amount) override;
		void	beRepaired(uint amount) override;
		void	highFivesGuys(void) const ;

}