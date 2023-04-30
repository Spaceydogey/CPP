/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:39:42 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/30 17:55:13 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : _type("default")
{
	std::cout << "\e[0;33mDefault AMateria constructor\e[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "\e[0;33mString AMateria constructor\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy AMateria constructor\e[0m" << std::endl;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "\e[0;31mDefault AMateria destructor\e[0m" << std::endl;
}


// Operators
AMateria & AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

//Member functions
std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

//Methode
void	AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}