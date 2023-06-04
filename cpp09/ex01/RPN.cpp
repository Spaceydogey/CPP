/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:25:35 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/04 20:33:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	isToken(int c)
{
	return ((c == '+' || c == '-' || c == '/' || c == '*'));
}

// Constructors
RPN::RPN()
{
	std::cout << "\e[0;33mDefault Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(std::string input)
{
	std::cout << "\e[0;33mInput Constructor called of RPN\e[0m" << std::endl;
	this->parsing(input);
}


RPN::RPN(const RPN &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}


// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called of RPN\e[0m" << std::endl;
}


// Operators
RPN & RPN::operator=(const RPN &assign)
{
	this->_stack = assign._stack;
	return *this;
}

// Private Functions

void	RPN::parsing(std::string input)
{
	const_iterator it;
	bool								isFirstLine = true;

	it = input.begin();
	while (it != input.end())
	{
		//first line
		if (isFirstLine)
		{
			it = this->push(it, input.end(), &isdigit);
			it = this->push(it, input.end(), &isdigit);
			it = this->push(it, input.end(), &isToken);
			isFirstLine = false;
		}	
		else
		{
			it = this->push(it, input.end(), &isdigit);
			it = this->push(it, input.end(), &isToken);
		}
	}
}


// Member Functions
int	RPN::compute()
{
	
	int token = this->_stack.top();
	this->_stack.pop();
	std::cout << token << std::endl;
	if (isToken(token))
	{
		int lhs;
		int rhs = this->_stack.top();
		this->_stack.pop();
		lhs = this->compute();
		return (this->op(token, lhs, rhs));
	}
	return (token);
}

RPN::const_iterator	RPN::push(RPN::const_iterator it, RPN::const_iterator end, int (*f)(int))
{
	while (it != end && *it == ' ')
		++it;
	if (it != end && f(*it))
	{
		// std::cout << *it << std::endl;
		if ((it + 1) != end && *(it + 1) != ' ')
			throw InputException();
		this->_stack.push(*it);
		++it;
	}
	else
		throw InputException();
	while (it != end && *it == ' ')
		++it;
	return (it);
}


	
// Excetpion

const char*	RPN::InputException::what() const throw()
{
	return ("Bad Input");
}