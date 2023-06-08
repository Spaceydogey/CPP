/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:26:47 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/08 14:20:23 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "BitCoinExchange.hpp"
#include <string>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: " << "Usage: ./btc [INPUT_FILE]" << std::endl;
		return (1);
	}
	try
	{
		BitCoinExchange	btc("data.csv");
		try
		{
			btc.value(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
}