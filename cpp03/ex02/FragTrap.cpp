/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:59 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 09:20:56 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "\e[0;33mDefault Constructor called of " << this->_name
				<< " the FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "\e[0;33mString Constructor called of " << this->_name
				<< " the FragTrap\e[0m" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of " << this->_name
				<< " the FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap() 
{
	std::cout << "\e[0;31mDestructor called of " << this->_name
				<< " the FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	
	this->_name = assign.getName();
	this->_hp = assign.getHp();
	this->_ep = assign.getEp();
	this->_ad = assign.getAd();
	return *this;
}

//Member function
void	FragTrap::highFivesGuys(void)
{
	if (this->_ep == 0 || this->_hp == 0)
	{
		std::cout << this->_name << " the Frag has no more hp or energy " << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << this->_name << " HIGH FIVE! " << std::endl;
}
