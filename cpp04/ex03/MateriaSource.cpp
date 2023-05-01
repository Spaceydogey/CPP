/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:05:27 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 15:04:45 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource() : _size(0)
{
	std::cout << "\e[0;33mDefault MateriaSource constructor\e[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &to_cp)
{
	*this = to_cp;
	std::cout << "\e[0;33mCopy MateriaSource constructor\e[0m" << std::endl;
}


// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_size; i++)
		delete this->_list[i];
	std::cout << "\e[0;31mDefault MateriaSource destructor\e[0m" << std::endl;
}



// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &rhs)
{
	(void)rhs;
	return *this;
}

		
//Member Functions
void    MateriaSource::learnMateria(AMateria *m)
{
	this->_list[this->_size] = m;
	this->_size += 1;
}

AMateria*    MateriaSource::createMateria(std::string const & type)
{
	int	i;

	i = -1;
	while (++i < this->_size)
		if (this->_list[i]->getType() == type)
			break;
	if (i < this->_size)
		return (this->_list[i]->clone());
	return (0);
}