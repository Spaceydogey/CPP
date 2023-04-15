/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:03:30 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/15 19:11:55 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(std::string lst[5], int size)
{
	int	j;

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

