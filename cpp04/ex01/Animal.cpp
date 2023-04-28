/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 16:49:59 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>


Animal::Animal() : _type("Animal")
{
	std::cout << "\e[0;33mDefault Animal constructor\e[0m" << std::endl;
}

Animal::Animal( const Animal & to_cp )
{
	std::cout << "Copy Animal constructor" << std::endl;
	*this = to_cp;
}


Animal::~Animal()
{
	std::cout << "\e[0;35mDefault Animal destructor\e[0m" << std::endl;
}



Animal &	Animal::operator=( Animal const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "No sound made" << std::endl;
}

Brain	*Animal::getBrain(void) const
{
	return (NULL);
}