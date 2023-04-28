/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 17:05:09 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>


AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "\e[0;33mDefault AAnimal constructor\e[0m" << std::endl;
}

AAnimal::AAnimal( const AAnimal & to_cp )
{
	std::cout << "Copy AAnimal constructor" << std::endl;
	*this = to_cp;
}


AAnimal::~AAnimal()
{
	std::cout << "\e[0;35mDefault AAnimal destructor\e[0m" << std::endl;
}



AAnimal &	AAnimal::operator=( AAnimal const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
