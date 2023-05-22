/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:51:09 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/21 13:21:45 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("default"),  _signed(false), _gradeToSign(150),
				_gradeToEx(150), _target("")
{
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m"
				<< std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), 
								_signed(false),
								_gradeToSign(copy.getGradeSign()),
								_gradeToEx(copy.getGradeEx()),
								_target("")
{
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
	*this = copy;
}


AForm::AForm(std::string name, int gradeToSign, int gradeToEx) : _name(name), 
														_signed(false),
														_gradeToSign(gradeToSign),
														_gradeToEx(gradeToEx),
														_target("")
{
	if (gradeToSign > 150 ||  gradeToEx > 150)
		throw AForm::GradeTooLowException();
	if (gradeToSign < 1 || gradeToEx < 1)
		throw AForm::GradeTooHighException();
	else 
		std::cout << "\e[0;33mAssignation Constructor called of AForm\e[0m"
				<< std::endl;
}


// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	this->_target = assign._target;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const AForm &f)
{
	out  <<"AForm name : " << f.getName() 
							<< ", Aform status : " << f.getSigned()
							<< ", grade to be signed : " << f.getGradeSign()
							<< ", grade to be executed : " << f.getGradeEx()
							<< ".";
	return (out);
}

// Getter
std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeEx() const
{
	return (this->_gradeToEx);
}

// MemberFunctions
void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

std::string	AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::setTarget(std::string new_target)
{
	this->_target = new_target;
}


// Exception
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


