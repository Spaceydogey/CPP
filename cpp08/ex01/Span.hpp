/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:01:44 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/03 13:49:10 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <limits>
# include <cmath>
# include <algorithm>

class Span
{
	public:
		// Constructors
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		void				addNumber(int newNbr);
		void				addNumberIt(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan (void);
		
	private:
		unsigned int		_size;
		std::vector<int>	_vect;

	class SpanFullExecption : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NoSpanExecption : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif