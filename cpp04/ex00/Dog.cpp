/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 15:38:58 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>


Dog::Dog() : Animal()
{
	std::cout << "\e[0;32mDefault Dog constructor\e[0m" << std::endl;
	this->_type = "Dog";
}

Dog::Dog( const Dog & to_cp )
{
	std::cout << "\e[0;32mCopy Dog constructor\e[0m" << std::endl;
	this->_type = "Dog";
	*this = to_cp;
}


Dog::~Dog()
{
	std::cout << "\e[0;31mDefault Dog destructor\e[0m" << std::endl;
}


Dog &	Dog::operator=( Dog const & rhs )
{
	(void)rhs;
	return (*this);
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}

void	Dog::makeSound(void) const
{
	std::cout << "woof" << std::endl;
}
