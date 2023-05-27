/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:39:36 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/27 15:43:58 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_array = NULL;
}


template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	if (n > 0)
		this->_array = new T[n];
	else
		this->_array = NULL;
}

template<typename T>
Array<T>::Array(const Array &copy)
{
	this->_size = 0;
	this->_array = NULL;
	*this = copy;
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array &assign)
{
	delete [] this->_array;
	this->_size = assign._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = assign._array[i];
	return *this;
}

template<typename T>
T	& Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw Array::ArrayOutOfRangeException();
	return (this->_array[i]);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}


template<typename T>
const char* Array<T>::ArrayOutOfRangeException::what() const throw()
{
	return ("Array out of range");
}

#endif