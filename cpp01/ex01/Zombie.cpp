/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:18:45 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/18 15:44:31 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " came back from the dead" << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "something came back from the dead" << std::endl;
}


Zombie::~Zombie()
{
	std::cout << this->_name << " died again" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
