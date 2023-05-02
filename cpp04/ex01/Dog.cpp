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
	this->_brain = new Brain;
}

Dog::Dog( const Dog & to_cp )
{
	std::cout << "\e[0;32mCopy Dog constructor\e[0m" << std::endl;
	this->_type = "Dog";
	this->_brain = NULL;
	*this = to_cp;
}


Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\e[0;31mDefault Dog destructor\e[0m" << std::endl;
}


Dog &	Dog::operator=( Dog const & rhs )
{
	delete this->_brain;
	this->_brain = new Brain(*rhs.getBrain());
	return (*this);
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "woof" << std::endl;
}
