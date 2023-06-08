/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:25:33 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/08 14:22:22 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <algorithm>
# include <sstream>
# include <exception>

class RPN
{
	public:
		// Type
		typedef std::string::const_iterator const_iterator;
		// Constructors
		RPN();
		RPN(std::string input);
		RPN(const RPN &copy);
		
		// Destructor
		~RPN();
		
		// Operators
		RPN & operator=(const RPN &assign);
		
		// Member Functions
		int				compute();
		const_iterator	push(const_iterator it, const_iterator end);
		
	
	private:
		std::stack<char>	_stack;
		void				parsing(std::string input);
		int					op(int token, int lhs, int rhs) const;
		int					add(int lhs, int rhs) const;
		int					minus(int lhs, int rhs) const;
		int					div(int lhs, int rhs) const;
		int					mult(int lhs, int rhs) const;
	
	//Exception
	class	InputException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};
	
	class	DivByZeroException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};
	class	ComputeException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};
};

#endif