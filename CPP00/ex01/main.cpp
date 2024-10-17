/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorhone <rkorhone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:52:57 by rkorhone          #+#    #+#             */
/*   Updated: 2024/10/17 13:52:58 by rkorhone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	PhoneBook		phonebook;
	std::string		input;

	// for testing
	// for (int i = 0; i < 8; i++) {
	// 	std::string a = "test " + std::to_string(i) + "";
	// 	phonebook.add_debug(a);
	// }

	while (1) {
		std::cout << "Enter command:\n\tADD\n\tSEARCH\n\tEXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input.empty())
			continue;
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			return 0;
		else
			std::cout << "Invalid command '" << input << "'" << std::endl;
	}
	return 0;
}
