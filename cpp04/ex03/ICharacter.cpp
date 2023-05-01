/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:06:26 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 10:06:27 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

// Constructors
ICharacter::ICharacter()
{
	std::cout << "\e[0;33mDefault Constructor called of ICharacter\e[0m" << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ICharacter\e[0m" << std::endl;
}


// Destructor
ICharacter::~ICharacter()
{
	std::cout << "\e[0;31mDestructor called of ICharacter\e[0m" << std::endl;
}


// Operators
ICharacter & ICharacter::operator=(const ICharacter &assign)
{
	(void) assign;
	return *this;
}

