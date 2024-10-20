#include "Zombie.hpp"
#include <iostream>
#include <string>

int	main() {

	Zombie *alpha = newZombie("alpha");
	alpha->announce();
	delete alpha;
	
	Zombie *beta = newZombie("beta");
	beta->announce();
	delete beta;

	randomChump("chump");

	return 0;
}
