/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:26:47 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/03 23:18:04 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "BitCoinExchange.hpp"
#include <string>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: " << "Usage: ./btc [INPUT_FILE1 INPUT_FILE2 ...]" << std::endl;
		return (1);
	}
	try
	{
		BitCoinExchange	btc("data.csv");
		for (int i = 1; i < ac; ++i)
		{
			try
			{
				btc.value(av[i]);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error : " << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
}