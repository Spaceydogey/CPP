/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:25:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/05 00:36:25 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: " << "Usage: ./RPN [INPUT_LINE]" << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn(av[1]);
		std::cout  << "Result : " << rpn.compute()  << std::endl;;	/* code */
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << '\n';
	}

	return (0);
}