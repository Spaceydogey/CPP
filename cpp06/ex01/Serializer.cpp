/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:13:10 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 11:49:48 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
	std::cout << "\e[0;33mDefault Constructor called of Serializer\e[0m" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Serializer\e[0m" << std::endl;
}


// Destructor
Serializer::~Serializer()
{
	std::cout << "\e[0;31mDestructor called of Serializer\e[0m" << std::endl;
}


// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{

}

Data*		Serializer::deserialize(uintptr_t raw)
{
	
}
