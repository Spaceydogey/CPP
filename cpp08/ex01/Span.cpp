/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:01:48 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/29 23:31:18 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span() : _size(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "\e[0;33mAssignation Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Span::~Span()
{
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	this->_size = assign._size;
	this->_vect = assign._vect;
	return (*this);
}

const char* Span::SpanFullExecption::what() const throw()
{
	return ("Span is full");
}

const char* Span::NoSpanExecption::what() const throw()
{
	return ("No span can be found");
}

void	Span::addNumber(int newNbr)
{
	if (this->_vect.size() + 1 > this->_size)
		throw Span::SpanFullExecption();
	this->_vect.push_back(newNbr);
}

void	Span::addNumberIt(std::vector<int>::iterator begin,
			std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > this->_size)
		throw Span::SpanFullExecption();
	this->_vect.insert(this->_vect.end(), begin, end);
}

int	Span::shortestSpan(void)
{
	if (this->_vect.size() <= 1)
		throw Span::NoSpanExecption();
	

	std::vector<int>::const_iterator end = this->_vect.end();
	std::vector<int>::const_iterator it1 = this->_vect.begin();
	std::vector<int>::const_iterator it2;
	int	min = std::abs(*(it1 + 1) - *it1);
	int	tmp;
	
	while (it1 != end)
	{
		it2 = it1 + 1;
		while (it2 != end)
		{
			tmp = std::abs(*it2 - *it1);
			if (it2 != it1 && tmp < min)
				min = tmp;
			++it2;
		}
		++it1;
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (this->_vect.size() <= 1)
		throw Span::NoSpanExecption();	
	std::vector<int>::const_iterator max 
				= std::max_element(this->_vect.begin(), this->_vect.end());
	std::vector<int>::const_iterator min
				= std::min_element(this->_vect.begin(), this->_vect.end());
	return (*max - *min);
}
