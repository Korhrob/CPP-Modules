
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

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

};