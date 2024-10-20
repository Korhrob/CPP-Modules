
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
		ClapTrap(const std::string name);
		~ClapTrap();

		virutal void	attack(const std::string& target);
		virutal void	takeDamage(unsigned int amount);
		virutal void	beRepaired(unsigned int amount);

};