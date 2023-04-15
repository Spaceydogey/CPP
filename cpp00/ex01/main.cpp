/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:02:59 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/15 19:25:08 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


int	main(void)
{
	PhoneBook	book;
	std::string	command;
	int			size;

	size = 0;
	while (1)
	{
		std::cout << ">Enter ADD, SEARCH or EXIT :" << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			book.add(size);
			if (size < MAX_SIZE)
				size++;
		}
		else if (command == "SEARCH")
			book.search(size);
	}
	return (0);
}