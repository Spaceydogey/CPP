/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:10:03 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/23 13:39:15 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string known_forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int			type;

	type = -1;
	for (int i = 0; i < 3; i++)
	{
		if (form == known_forms[i])
		{
			type = i;
			break;
		}
	}
	switch (type)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default :
			throw Intern::UnknownFormException();
			
	}

}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Form does not exist");
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Intern &object)
{
	(void)object;
	stream << "Intern";
	return stream;
}
