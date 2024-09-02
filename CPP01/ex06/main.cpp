#include "Harl.hpp"
#include <iostream>
#include <string>



int	main(int argc, char **argv)
{
	Harl harl;

	if (argc > 1)
	{
		std::string	str = argv[1];
		int			level = -1;
		for (int i = 0; i < 4; i++)
		{
			if (str == harl.getFilterLevel(i))
			{
				level = i;
				break;
			}
		}
		if (level < 0)
		{
			std::cout << "Invalid filter" << std::endl;
			return 1;
		}
		harl.setFilterLevel(level);
	}

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UKNOWN");
	return 0;
}