
#include <string>

class	ClapTrap
{

	private:

		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energy;
		unsigned int	attackDamage;

	public:

		ClapTrap();
		ClapTrap(const std::string name, unsigned int hitPoints, unsigned int energy, unsigned int attackDamage);
		ClapTrap(const std::string name) : ClapTrap(name, 10, 50, 20) {}
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};