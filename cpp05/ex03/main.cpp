/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:20:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/23 14:14:37 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(time(0));
	try
	{
		std::cout << "--- TEST 1 ---" << std::endl << std::endl	;
		AForm		*f1;
		Bureaucrat	a("boop", 1);
		Intern		b;
		
		f1 = b.makeForm("ShrubberyCreationForm", "beep");
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << *f1 << std::endl;

		a.signForm(*f1);
		std::cout << *f1 << std::endl;
		a.executeForm(*f1);
		delete (f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "--- TEST 1 ---" << std::endl << std::endl	;
		AForm		*f1;
		Bureaucrat	a("boop", 1);
		Intern		b;
		
		f1 = b.makeForm("ShrubberyCreationForm", "beep");
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << *f1 << std::endl;

		a.signForm(*f1);
		std::cout << *f1 << std::endl;
		a.executeForm(*f1);
		delete (f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << "--- TEST 2 ---" << std::endl << std::endl	;
		AForm		*f1;
		Bureaucrat	a("boop", 1);
		Intern		b;
		
		f1 = b.makeForm("RobotomyRequestForm", "beep");
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << *f1 << std::endl;

		a.signForm(*f1);
		std::cout << *f1 << std::endl;
		a.executeForm(*f1);
		delete (f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << "--- TEST 3 ---" << std::endl << std::endl	;
		AForm		*f1;
		Bureaucrat	a("boop", 1);
		Intern		b;
		
		f1 = b.makeForm("PresidentialPardonForm", "beep");
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << *f1 << std::endl;

		a.signForm(*f1);
		std::cout << *f1 << std::endl;
		a.executeForm(*f1);
		delete (f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "--- TEST 4 ---" << std::endl << std::endl	;
		AForm		*f1;
		Bureaucrat	a("boop", 1);
		Intern		b;
		
		f1 = b.makeForm("yes", "beep");
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << *f1 << std::endl;

		a.signForm(*f1);
		std::cout << *f1 << std::endl;
		a.executeForm(*f1);
		delete (f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
