/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 17:06:42 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>


Cat::Cat() : AAnimal()
{
	std::cout << "\e[0;32mDefault Cat constructor\e[0m" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat( const Cat & to_cp )
{
	std::cout << "\e[0;32mCopy Cat constructor\e[0m" << std::endl;
	*this = to_cp;
}


Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\e[0;31mDefault Cat destructor\e[0m" << std::endl;
}



Cat &	Cat::operator=( Cat const & rhs )
{
	this->_type = rhs.getType();
	this->_brain = new Brain(*rhs.getBrain());
	return (*this);
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "moew" << std::endl;
}
