/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:43:15 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/23 14:20:36 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
	this->setTarget("default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "\e[0;33mAssignation Constructor called of RobotomyRequestForm\e[0m" << std::endl;
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->setTarget(assign.getTarget());
	return *this;
}

//Methode
void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int check;

	this->AForm::execute(executor);
	check = std::rand() % 2;
	if (check == 0)
		std::cout << "*bzzz bzzzz* " << this->getTarget()
			<< " has been robotomized *bzzz bzzzz*" << std::endl;
	else
		std::cout << "*bzzz bzzzz* robotomy  on "
			<< this->getTarget() << " failed *bzzz bzzzz*" << std::endl;
}
