/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 11:53:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "\e[0;33mDefault WrongCat constructor\e[0m" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat & to_cp )
{
	std::cout << "Copy WrongCat constructor" << std::endl;
	*this = to_cp;
}


WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDefault WrongCat destructor\e[0m" << std::endl;
}



WrongCat &	WrongCat::operator=( WrongCat const & rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

std::string	WrongCat::getType(void) const
{
	return (this->_type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "wooof" << std::endl;
}
