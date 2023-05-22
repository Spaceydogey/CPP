/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:20:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/20 18:18:10 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat	b("boop", 1);	
		Form		f("oi", 1, 1);
		
		std::cout << "Bureaucrat : " << b << std::endl;
		std::cout << "Form : " << f << std::endl;
		b.signeForm(f);
		std::cout << "Form : " << f << std::endl;
		b.lower();
		std::cout << "Bureaucrat : " << b << std::endl;
		b.signeForm(f);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		/* do some stuff with bureaucrats */
		Form		f("oi", 0, 1);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		/* do some stuff with bureaucrats */
		Form		f("oi", 1, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		/* do some stuff with bureaucrats */
		Form		f("oi", 151, 1);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		/* do some stuff with bureaucrats */
		Form		f("oi", 1, 151);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
