/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:58:29 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 13:47:46 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character() : _name("default")
{
	std::cout << "\e[0;33mDefault Character constructor\e[0m" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &to_cp) _name(to_cp.getName())
{
	std::cout << "\e[0;33mCopy Character constructor\e[0m" << std::endl;
	*this = to_cp;
}


// Destructor
Character::~Character()
{
	for (int i = 0; i < INV_SIZE; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	std::cout << "\e[0;31mDefault Character destructor\e[0m" << std::endl;
}


// Operators
Character & Character::operator=(const Character &rhs)
{
	for (int i = 0; i < INV_SIZE; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	for (int i = 0; i < INV_SIZE; i++)
		this->_inventory[i] = to_cp.getMateria(i);
	return *this;
}

//Member Functions
std::string const   &getName() const
{
	return (this->_name);
}

AMateria            &getMateria(int idx) const
{
	if (idx < 4 && idx >=0)
		return (this->_inventory[i]);
	return (NULL);
}

void                equip(AMateria* m)
{
	int i;

	i = -1;
	while (this->_inventory[++i] && i < INV_SIZE);
	if (i < INV_SIZE)
		this->_inventory[i] = m;
}

void                unequip(int idx);
{
	if (idx < INV_SIZE)
		this->_inventory[i] = NULL;
}

void                use(int idx, ICharacter& target)
{
	if (!this->_inventory[idx] || idx > INV_SIZE || idx < 0)
		return ;
	this->_inventory[idx]->use(target);
}