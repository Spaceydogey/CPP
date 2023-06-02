/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:26:47 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/02 16:58:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "BitCoinExchange.hpp"
#include <string>

int		open_error(int err)
{
	switch (err)
	{
		default:
			std::cerr << "Error: ";
		case 0:
			std::cerr << "Bad open on: data.csv" << std::endl;
			break ;
		case 1:
			std::cerr << "Bad open on: input file" << std::endl;
			break ;
	}
	return (2);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: " << "Usage: ./btc [INPUT_FILE]" << std::endl;
		return (1);
	}

	std::ifstream data;
	(void)av;
	data.open ("data.csv");
	// BitCoinExchange	btc("data.csv");
	std::string line;
	std::string date;
	std::string ex;
	std::getline(data, line);
	std::cout << line << std::endl ;
	std::stringstream ss(line);
	std::getline(ss, date, ',');
	std::getline(ss, ex);
	std::cout << date << " " << ex << std::endl ;
	std::getline(data, line);
	// for (int i = 1; i < ac; ++i)
	// {
	// 	btc.value(av[i]);
	// }	
}