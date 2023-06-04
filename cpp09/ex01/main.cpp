/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:25:32 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/04 19:52:56 by hdelmas          ###   ########.fr       */
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
	RPN	rpn(av[1]);
	rpn.compute();
	return (0);
}