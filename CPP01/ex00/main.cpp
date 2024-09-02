
#include <iostream>
#include <string>
#include "Zombie.hpp"

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