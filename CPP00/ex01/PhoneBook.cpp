#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	curIndex = 0;
	offset = 0;
}

PhoneBook::~PhoneBook()
{

}

std::string	PhoneBook::truncate(std::string str, int len) {
	std::string out;

	out = str;
	if (out.length() > len) {
		out = str.substr(0, len - 1) + ".";
	}
	return out;
}

void	PhoneBook::add()
{
	Contact		temp;
	std::string input;

	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, temp.first_name);
	if (temp.first_name.empty())
	{
		std::cout << "Can't have an empty field!" << std::endl;
		return;
	}

	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, temp.last_name);
	if (temp.last_name.empty())
	{
		std::cout << "Can't have an empty field!" << std::endl;
		return;
	}

	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, temp.nickname);
	if (temp.nickname.empty())
	{
		std::cout << "Can't have an empty field!" << std::endl;
		return;
	}

	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, temp.phone_number);
	if (temp.phone_number.empty())
	{
		std::cout << "Can't have an empty field!" << std::endl;
		return;
	}

	std::cout << "Enter their darkest secret:" << std::endl;
	std::getline(std::cin, temp.secret);
	if (temp.secret.empty())
	{
		std::cout << "Can't have an empty field!" << std::endl;
		return;
	}

	contacts[curIndex % 8].first_name = temp.first_name;
	contacts[curIndex % 8].last_name = temp.last_name;
	contacts[curIndex % 8].nickname = temp.nickname;
	contacts[curIndex % 8].phone_number = temp.phone_number;
	contacts[curIndex % 8].secret = temp.secret;

	curIndex++;
	if (curIndex > 7)
		offset++;
}

void	PhoneBook::add_debug(std::string input)
{
	contacts[curIndex % 8].first_name = input;
	contacts[curIndex % 8].last_name = input;
	contacts[curIndex % 8].nickname = input;
	contacts[curIndex % 8].phone_number = input;
	contacts[curIndex % 8].secret = input;

	curIndex++;
	if (curIndex > 8)
		offset++;
}

void	PhoneBook::search()
{
	std::string input;

	std::cout << std::right 
	<< std::setw(10) << "index" << "|" 
	<< std::setw(10) << "first_name" << "|" 
	<< std::setw(10) << "last_name" << "|" 
	<< std::setw(10) << "nickname" << std::endl;

	int i = 0, j = 0;
	while (i < 8 && i < curIndex) {
		j = (i + offset) % 8;
		std::cout << std::right
			<< std::setw(10) << i << "|"
			<< std::setw(10) << truncate(contacts[j].first_name, 10) << "|" 
			<< std::setw(10) << truncate(contacts[j].last_name, 10) << "|" 
			<< std::setw(10) << truncate(contacts[j].nickname, 10) << std::endl;
		i++;
	}

	std::cout << "Enter index:" << std::endl;
	std::getline(std::cin, input);

	try {
		int nb = std::stoi(input);

		if (nb >= 0 && (nb < 8 && nb < curIndex)) {
			// contacts[(nb + curIndex) % 8].print();
			std::cout << contacts[(nb + curIndex) % 8].first_name << std::endl;
			std::cout << contacts[(nb + curIndex) % 8].last_name << std::endl;
			std::cout << contacts[(nb + curIndex) % 8].first_name << std::endl;
			std::cout << contacts[(nb + curIndex) % 8].first_name << std::endl;
			std::cout << contacts[(nb + curIndex) % 8].first_name << std::endl;
		} else {
			std::cout << "Invalid index" << std::endl;
		}
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
