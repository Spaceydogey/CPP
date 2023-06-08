/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:25:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/08 14:23:44 by hdelmas          ###   ########.fr       */
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
		int res = rpn.compute();
		std::cout  << "Result : " << res  << std::endl;;	/* code */
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << '\n';
	}

	return (0);
}