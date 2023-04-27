/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:07:02 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 09:25:20 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _name("default"), _hp(10), _ep(10), _ad(0)
{
		std::cout << "\e[0;33mDefault Constructor called of " << this->_name
				<< " the ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of " << this->_name
				<< " the ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
		std::cout << "\e[0;33mString Constructor called of " << this->_name
				<< " the ClapTrap\e[0m" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of " << this->_name
				<< " the ClapTrap\e[0m" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	this->_name = assign.getName();
	this->_hp = assign.getHp();
	this->_ep = assign.getEp();
	this->_ad = assign.getAd();
	return *this;
}


//Member function
void	ClapTrap::attack(const std::string &target)
{
	if (this->_ep == 0 || this->_hp == 0)
	{
		std::cout << this->_name << " has no more hp or energy " << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << this->_name << " attacks " << target << ", causing "
				<< this->_ad << " points of damage!"<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " is already broken" << std::endl;
		return ;
	}		
	if (amount > this->_hp)
		amount = this->_hp;
	this->_hp -= amount;
	if (_hp == 0)
		std::cout << this->_name << " took " << amount 
					<< " of damage, and broke" << std::endl;
	else
		std::cout << this->_name << " took " << amount 
					<< " of damage, current hp is now : " << this->_hp
					<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep == 0 || this->_hp == 0)
	{
		std::cout << this->_name << " has no more hp or energy " << std::endl;
		return ;
	}

	unsigned int new_hp;

	this->_ep -= 1;
	new_hp = this->_hp + amount;
	if (new_hp < this->_hp)
	{
		new_hp = 4294967295; //UINT MAX
		amount = new_hp - this->_hp;
	}
	this->_hp = new_hp;
	std::cout << this->_name << " was repaired of " << amount 
				<< " hp, current hp is now : " << this->_hp
				<< std::endl;	
}

unsigned int	ClapTrap::getHp(void) const
{
	return (this->_hp);
}
unsigned int	ClapTrap::getEp(void) const
{
	return (this->_ep);
}
unsigned int	ClapTrap::getAd(void) const
{
	return (this->_ad);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
	return ;
}