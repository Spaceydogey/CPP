/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:50:41 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/26 19:36:01 by hdelmas          ###   ########.fr       */
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
	*this = copy;
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
	this->_name = assign.getName();
	this->_hp = assign.getHp();
	this->_ep = assign.getEp();
	this->_ad = assign.getAd();
	return *this;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "Diamond name : " << this->_name 
				<< " Clap trap name : " << this->getName() << std::endl;
}



