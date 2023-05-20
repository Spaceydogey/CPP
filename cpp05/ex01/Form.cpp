/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:51:09 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/20 18:14:12 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form() : _name("default"),  _signed(false), _gradeToSign(150),
				_gradeToEx(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m"
				<< std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), 
								_signed(copy.getSigned()),
								_gradeToSign(copy.getGradeSign()),
								_gradeToEx(copy.getGradeEx())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


Form::Form(std::string name, int gradeToSign, int gradeToEx) : _name(name), 
														_signed(false),
														_gradeToSign(gradeToSign),
														_gradeToEx(gradeToEx)
{
	if (gradeToSign > 150 ||  gradeToEx > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToEx < 1)
		throw Form::GradeTooHighException();
	else 
		std::cout << "\e[0;33mAssignation Constructor called of Form\e[0m"
				<< std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Form &f)
{
	out  <<"Form name : " << f.getName() 
							<< ", form status : " << f.getSigned()
							<< ", grade to be signed : " << f.getGradeSign()
							<< ", grade to be executed : " << f.getGradeEx()
							<< "." << std::endl;
	return (out);
}

// Getter
std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeEx() const
{
	return (this->_gradeToEx);
}

// MemberFunctions
void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}


// Exception
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


