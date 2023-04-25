/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:59 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/25 20:38:10 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "\e[0;33mDefault Constructor called of " << this->_name
				<< " the ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "\e[0;33mString Constructor called of " << this->_name
				<< " the ScavTrap\e[0m" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of " << this->_name
				<< " the ScavTrap\e[0m" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "\e[0;31mDestructor called of " << this->_name
				<< " the ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	
	this->_name = assign.getName();
	this->_hp = assign.getHp();
	this->_ep = assign.getEp();
	this->_ad = assign.getAd();
	return *this;
}

//Member function
void	ScavTrap::attack(const std::string &target) const
{
	std::cout << "\e[1;35m"<< this->_name << " the Scav attacks " 
				<< target << ", causing " << this->_ad
				<< " points of damage!\e[0m"<< std::endl;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << this->_name << " entered in Gate Keeper mode " << std::endl;
}
