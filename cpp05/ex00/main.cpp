/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:20:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/19 18:16:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		/* do some stuff with bureaucrats */
		
		std::cout << Bureaucrat("boop", 1) << std::endl;
		std::cout << Bureaucrat("boop", 2) << std::endl;
		std::cout << Bureaucrat("boop", 150) << std::endl;
		std::cout << Bureaucrat("boop", 151) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	try
	{
		/* do some stuff with bureaucrats */
		
		std::cout << Bureaucrat("boop", 1) << std::endl;
		std::cout << Bureaucrat("boop", 2) << std::endl;
		std::cout << Bureaucrat("boop", 120) << std::endl;
		std::cout << Bureaucrat("boop", -18) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}