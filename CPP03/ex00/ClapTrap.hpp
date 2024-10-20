
#include <string>

class	ClapTrap
{

	private:

		std::string	name;
		uint		hitPoints = 10;
		uint		energy = 50;
		uint		attackDamage = 20;

	public:

		ClapTrap();
		ClapTrap(std::string name);
		// ORTHODOX CANONICAL; ADD COPY AND COPY ASSIGN TO THIS AND FUTURE CLASS
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(uint amount);
		void	beRepaired(uint amount);

};