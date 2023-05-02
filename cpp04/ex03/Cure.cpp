/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:07:45 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/30 19:07:46 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure")
{
	std::cout << "\e[0;33mDefault Cure constructor\e[0m" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	std::cout << "\e[0;33mCopy Cure constructor\e[0m" << std::endl;
	(void)copy;
}


// Destructor
Cure::~Cure()
{
	std::cout << "\e[0;31mDefault Cure destructor\e[0m" << std::endl;
}


// Operators
Cure & Cure::operator=(const Cure &rhs)
{
	(void)rhs;
	return *this;
}

//Methodes
AMateria *	Cure::clone () const
{
    return (new Cure());
}

void		Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
