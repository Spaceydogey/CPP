/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:07:45 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/02 15:08:43 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice")
{
	std::cout << "\e[0;33mDefault Ice constructor\e[0m" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	std::cout << "\e[0;33mCopy Ice constructor\e[0m" << std::endl;
	(void)copy;
}


// Destructor
Ice::~Ice()
{
	std::cout << "\e[0;31mDefault Ice destructor\e[0m" << std::endl;
}


// Operators
Ice & Ice::operator=(const Ice &rhs)
{
	(void) rhs;
	return *this;
}

//Methodes
AMateria *	Ice::clone () const
{
    return (new Ice());
}

void		Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
