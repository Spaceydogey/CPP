/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:20:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/23 14:08:14 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main()
{
	std::srand(time(0));
	try
	{
		std::cout << "--- TEST 1 ---" << std::endl << std::endl	;
		Bureaucrat	a("boop", 150);
		Bureaucrat	b("beep", 10);
		ShrubberyCreationForm	f1("tree");

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f1 << std::endl;

		a.signForm(f1);
		b.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
		b.executeForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "--- TEST 2 ---" << std::endl << std::endl	;

		Bureaucrat	a("boop", 150);
		Bureaucrat	b("beep", 10);
		RobotomyRequestForm	f1("robot");

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f1 << std::endl;

		a.signForm(f1);
		b.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
		b.executeForm(f1);
		b.executeForm(f1);
		b.executeForm(f1);
		b.executeForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "--- TEST 3 ---" << std::endl << std::endl	;

		Bureaucrat	a("boop", 150);
		Bureaucrat	b("beep", 10);
		Bureaucrat	c("oi", 1);
		PresidentialPardonForm	f1("pres");

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f1 << std::endl;

		a.signForm(f1);
		b.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
		b.executeForm(f1);
		c.executeForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "--- TEST 4 ---" << std::endl << std::endl	;

		Bureaucrat	a("boop", 150);
		Bureaucrat	b("beep", 10);
		ShrubberyCreationForm	f1("tree");
		RobotomyRequestForm	f2("robot");
		PresidentialPardonForm	f3("pres");

		std::cout << a << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		a.executeForm(f1);
		a.executeForm(f2);
		a.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
