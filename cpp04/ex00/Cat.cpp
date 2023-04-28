/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 16:05:29 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>


Cat::Cat() : Animal()
{
	std::cout << "\e[0;32mDefault Cat constructor\e[0m" << std::endl;
	this->_type = "Cat";
}

Cat::Cat( const Cat & to_cp )
{
	std::cout << "\e[0;32mCopy Cat constructor\e[0m" << std::endl;
	*this = to_cp;
}


Cat::~Cat()
{
	std::cout << "\e[0;31mDefault Cat destructor\e[0m" << std::endl;
}



Cat &	Cat::operator=( Cat const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}

void	Cat::makeSound(void) const
{
	std::cout << "moew" << std::endl;
}
