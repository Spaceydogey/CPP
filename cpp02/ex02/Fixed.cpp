/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:09:15 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 15:54:55 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const Fixed::_binPointPos = 8;


Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int	integer)
{
	// std::cout << "Integer constructor called" << std::endl;
	this->_value = integer << Fixed::_binPointPos;
}

Fixed::Fixed(float	floating)
{
	// std::cout << "Floating constructor called" << std::endl;
	this->_value = roundf(floating * (float)(1 << Fixed::_binPointPos));
}

Fixed::~Fixed()
{
	// std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &to_cp)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = to_cp;
}

// Comparison operators
bool 	Fixed::operator==(Fixed const &rhs)
{
	return (this->_value == rhs.getRawBits());
}

bool 	Fixed::operator<(Fixed const &rhs)
{
	return (this->_value < rhs.getRawBits());
}

bool 	Fixed::operator<=(Fixed const &rhs)
{
	return (*this < rhs || *this == rhs);
}

bool 	Fixed::operator!=(Fixed const &rhs)
{
	return (!(*this == rhs));
}

bool 	Fixed::operator>(Fixed const &rhs)
{
	return (!(*this <= rhs));
}

bool 	Fixed::operator>=(Fixed const &rhs)
{
	return (!(*this < rhs));
}

// Arithmetic operators
Fixed 	& Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	Fixed	res;

	res.setRawBits((this->_value + rhs.getRawBits()));
	return (res);
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	Fixed	res;
	
	res.setRawBits((this->_value - rhs.getRawBits()));
	return (res);
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	Fixed	res;

	res._value = this->_value * rhs._value;
	res._value = res._value >> (Fixed::_binPointPos);
	return (res);
}




//Increment operators
Fixed	Fixed::operator++(int)
{	
	Fixed	tmp;

	tmp = *this;
	this->_value += 1;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{	
	Fixed	tmp;

	tmp = *this;
	this->_value -= 1;
	return (tmp);
}

Fixed	& Fixed::operator++(void)
{
	this->_value += 1;
	return(*this); 
}

Fixed	& Fixed::operator--(void)
{
	this->_value += 1;
	return(*this); 
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits function called" << std::endl;
	return(this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits function called" << std::endl;
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
