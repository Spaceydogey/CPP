/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:03:30 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/16 12:10:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <stdlib.h>



PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

static void	make_lst(std::string res[5])
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

void	PhoneBook::add(int size)
{
	int	j;
	std::string	lst[5];

	make_lst(lst);
	if (size == MAX_SIZE)
	{
		j = -1;
		while (++j < MAX_SIZE - 1)
		{
			this->_contacts[j] = this->_contacts[j + 1];
		}
		this->_contacts[MAX_SIZE - 1].set_contact(lst[0], lst[1], lst[2], lst[3], lst[4]);
	}
	else
		this->_contacts[size].set_contact(lst[0], lst[1], lst[2], lst[3], lst[4]);
	return ;
}

Contact	PhoneBook::get_contact(int index)
{
	return (this->_contacts[index]);
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

void	PhoneBook::search(int size)
{
	std::string	index_str;
	int			i;
	int			index;

	i = -1;
	if (size == 0)
		return ;
	while (++i < size)
	std::cout << format_index() << i << this->_contacts[i].get_listing() << std::endl;
	std::cout << ">Enter the contact's index :" << std::endl;
	std::getline(std::cin, index_str);
	if (index_str.size() != 1 || !isdigit(index_str[0]))
		return (search(size));
	index = atoi(index_str.c_str());
	if (index >= MAX_SIZE || index < 0)
		std::cout << "Error : index out of range" << std::endl;
	else
		std::cout << this->_contacts[index].get_display();
}