#pragma once

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact	contacts[8];
	int		curIndex;
	int		offset;
	std::string truncate(std::string, int len);

	public:
	void	add();
	void	add_debug(std::string input);
	void	search();

	PhoneBook();
	~PhoneBook();
};
