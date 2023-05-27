/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:39:41 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/27 15:39:42 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template<typename T>
class Array
{
	public:
		// Constructors
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(const Array &copy);
		
		// Destructor
		~Array<T>();
		
		// Operators
		Array<T> 		& operator=(const Array &assign);
		T				& operator[](unsigned int i) const;
		unsigned int	size() const;
		
		class ArrayOutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		
	private:
		unsigned int	_size;
		T				*_array;
		
};

#endif