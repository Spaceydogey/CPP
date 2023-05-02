/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:58:29 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/02 14:56:22 by hdelmas          ###   ########.fr       */
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


Character::Character(std::string name) : _name(name)
{
	std::cout << "\e[0;33mString Character constructor\e[0m" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &to_cp) : _name(to_cp.getName())
{
	std::cout << "\e[0;33mCopy Character constructor\e[0m" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		this->_inventory[i] = NULL;
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
		if (rhs.getMateria(i))
			this->_inventory[i] = rhs.getMateria(i)->clone();
	return *this;
}

//Member Functions
std::string const   &Character::getName() const
{
	return (this->_name);
}

AMateria            *Character::getMateria(int idx) const
{
	if (idx < 4 && idx >=0)
		return (this->_inventory[idx]);
	return (NULL);
}

void               Character::equip(AMateria* m)
{
	int i;

	i = -1;
	while (++i < INV_SIZE && this->_inventory[i] );
	if (i < INV_SIZE)
		this->_inventory[i] = m;
	else
	{
		std::cout << "Inventory is full " << m->getType() << " has been discared" << std::endl;
		delete m;
	}
}

void                Character::unequip(int idx)
{
	if (idx < INV_SIZE && idx >= 0)
	{
		std::cout << "Slot " << idx << " cleared" << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void                Character::use(int idx, ICharacter& target)
{
	if (idx >= INV_SIZE || idx < 0 || !this->_inventory[idx] )
		return ;
	this->_inventory[idx]->use(target);
}