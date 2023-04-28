/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:14:24 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 15:17:09 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &to_cp)
{
	*this = to_cp;
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs.getIdea(i);
	return *this;
}

std::string	Brain::getIdea(int id) const
{
	if (id < 0 || id >= 100)
		return ("Index out of range"); 
	return (this->_ideas[id]);
}

int	Brain::setIdea(std::string newIdea, int id)
{
	if (id < 0 || id >= 100)
		return (-1);
	this->_ideas[id] = newIdea;
	return (0);
}

int	Brain::delIdea(int id)
{
	if (id < 0 || id >= 100)
		return (-1); 
	this->_ideas[id] = "";
	return (0);
}
