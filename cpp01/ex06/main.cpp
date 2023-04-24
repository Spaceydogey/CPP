/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 11:03:13 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	Harl	harl;
	
	if (ac != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
}