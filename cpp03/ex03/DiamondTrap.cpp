/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:50:41 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 09:26:06 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"



DiamondTrap::DiamondTrap() : _name("default")
{
	std::cout << "\e[0;33mDefault Constructor called of " << this->_name
				<< " the DiamondTrap\e[0m" << std::endl;
	this->setName(this->_name + "_clap_name");
	this->_ad = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap & to_cp )
{
	*this = to_cp;
	std::cout << "\e[0;33mCopy Constructor called of " << this->_name
				<< " the DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :	ScavTrap(name),
												FragTrap(name), _name(name)
{
	std::cout << "\e[0;33mString Constructor called of " << this->_name
				<< " the DiamondTrap\e[0m" << std::endl;
	this->setName(name + "_clap_name");

	this->_ad = 30;
}



DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mString Constructor called of " << this->_name
				<< " the DiamondTrap\e[0m" << std::endl;
}


DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_ep == 0 || this->_hp == 0)
	{
		std::cout << this->_name << " the Diamond has no more hp or energy " << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << "Diamond name : " << this->_name 
				<< " Clap trap name : " << this->getName() << std::endl;
}



