/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:09:15 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/21 16:19:48 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const Fixed::_binPointPos = 8;


Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int	integer)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_value = integer << Fixed::_binPointPos;
}

Fixed::Fixed(float	floating)
{
	std::cout << "Floating constructor called" << std::endl;
	this->_value = roundf(floating * (float)(1 << Fixed::_binPointPos));
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &to_cp)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_cp;
}

Fixed 	& Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called" << std::endl;
	return(this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_binPointPos);
}

float	Fixed::toFloat(void) const
{
	return (this->_value / ((float)(1 << Fixed::_binPointPos)));
}

std::ostream	&  operator<<(std::ostream &o, Fixed const &rhs)
{

	std::cout << rhs.toFloat();
	return (o);	
}

int  Fixed::getbinPointPos(void)
{
	return (Fixed::_binPointPos);
}
