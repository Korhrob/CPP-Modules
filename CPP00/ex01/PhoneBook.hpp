/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorhone <rkorhone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:53:13 by rkorhone          #+#    #+#             */
/*   Updated: 2024/10/17 13:53:15 by rkorhone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
