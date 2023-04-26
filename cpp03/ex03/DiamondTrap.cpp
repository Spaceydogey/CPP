/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:50:41 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/26 16:39:26 by hdelmas          ###   ########.fr       */
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
	// this->attack = &ScavTrap::attack;
}

DiamondTrap::DiamondTrap( const DiamondTrap & to_cp )
{
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), _name(name)
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

// void			DiamondTrap::attack(const std::string& target) const
// {
// 	// ScavTrap::attack(target);
// 	std::cout << "oi" << std::endl;
// }



DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}

std::string DiamondTrap::getName(void) const
{
	return (this->_name);
}



