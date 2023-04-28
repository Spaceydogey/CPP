/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 11:53:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>


WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "\e[0;33mDefault WrongAnimal constructor\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & to_cp )
{
	std::cout << "Copy WrongAnimal constructor" << std::endl;
	*this = to_cp;
}


WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDefault WrongAnimal destructor\e[0m" << std::endl;
}



WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "No sound made" << std::endl;
}
