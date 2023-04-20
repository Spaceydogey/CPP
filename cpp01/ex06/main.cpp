/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/20 19:50:47 by hdelmas          ###   ########.fr       */
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
	}
	harl.complain(av[1]);
}