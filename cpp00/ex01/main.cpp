/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:02:59 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/15 19:14:18 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

static void	add(std::string res[5])
{
	std::cout << ">Enter the contact's first name :" << std::endl;
	std::getline(std::cin, res[0]);
	std::cout << ">Enter the contact's last name :" << std::endl;
	std::getline(std::cin, res[1]);
	std::cout << ">Enter the contact's nickname :" << std::endl;
	std::getline(std::cin, res[2]);
	std::cout << ">Enter the contact's phone number :" << std::endl;
	std::getline(std::cin, res[3]);
	std::cout << ">Enter the contact's darkest secret :" << std::endl;
	std::getline(std::cin, res[4]);
}

static std::string	format_index(void)
{
	int			i;
	std::string	res;
	
	i = -1;
	res +=  "|";
	while (++i < 9)
		res += " ";
	return (res);
}

static void	search(PhoneBook book, int size)
{
	std::string	index_str;
	int			i;
	int			index;
	
	i = -1;
	while (++i < size)
	std::cout << format_index() << i << book.get_contact(i).get_listing() << std::endl;
	std::cout << ">Enter the contact's index :" << std::endl;
	std::getline(std::cin, index_str);
	if (index_str.size() != 1 || !isdigit(index_str[0]))
		return (search(book, size));
	index = atoi(index_str.c_str());
	if (index >= MAX_SIZE || index < 0)
		std::cout << "Error : index out of range" << std::endl;
	else
		std::cout << book.get_contact(index).get_display();
}

int	main(void)
{
	PhoneBook	book;
	std::string	command;
	std::string	lst[5];
	int			size;

	size = 0;
	while (1)
	{
		std::cout << ">Enter ADD, SEARCH or EXIT :" << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			exit(0);
		else if (command == "ADD")
		{
			add(lst);
			book.add(lst, size);
			if (size < MAX_SIZE)
				size++;
		}
		else if (command == "SEARCH")
			search(book, size);
	}
	return (0);
}