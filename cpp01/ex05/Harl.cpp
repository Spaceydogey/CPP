/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:25:21 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/20 19:29:08 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	this->_fct[0] = &Harl::_debug;
	this->_fct[1] = &Harl::_info;
	this->_fct[2] = &Harl::_warning;
	this->_fct[3] = &Harl::_error;
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::_debug(void) const
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money." 
			<< " You didn't put enough bacon in my burger! If you did,"
			<< " I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free."
			<< " I've been coming for years whereas you started working"
			<< " here since last month." << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}

void	Harl::complain(std::string level) const
{
	int			i = -1;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	while (++i < 4)
	{
		if (!levels[i].compare(level))
		{
			(this->*_fct[i])();
			break ;
		} 
	}
	if (i == 4)
		std::cout << "Error: invalid level indentifier." << std::endl;
}	


