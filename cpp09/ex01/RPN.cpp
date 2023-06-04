/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:25:35 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/05 01:11:33 by hdelmas          ###   ########.fr       */
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
	const_iterator 	it;
	int				count = 0;
	int				tokenCount = 0;

	it = input.begin();
	while (it != input.end())
	{
		while (it != input.end() && *it == ' ')
			++it;
		if (it != input.end() && (isToken(*it)))
		{
			while (it != input.end() && (isToken(*it)))
			{
				it = this->push(it, input.end());
				++tokenCount;
				++it;
				while (it != input.end() && *it == ' ')
					++it;
			}
			if (tokenCount != count - 1)
				throw InputException();
		}
		else if (it != input.end())
		{
			it = this->push(it, input.end());
			++count;
			++it;
		}
	}
}

int					RPN::op(int token, int lhs, int rhs) const
{
	switch (token)
	{
		case '+' :
			return (this->add(lhs, rhs));
		case '-' :
			return (this->minus(lhs, rhs));
		case '/' :
			return (this->div(lhs, rhs));
		case '*' :
			return (this->mult(lhs, rhs));
		default :
			throw ComputeException();
			return (0);
	}
	
}

int					RPN::add(int lhs, int rhs) const
{
	return (lhs + rhs);
}

int					RPN::minus(int lhs, int rhs) const
{
	return (lhs - rhs);
}

int					RPN::div(int lhs, int rhs) const
{
	if (rhs == 0)
		throw DivByZeroException();
	return (lhs / rhs);
}

int					RPN::mult(int lhs, int rhs) const
{
	return (lhs * rhs);
}



// Member Functions
int	RPN::compute()
{
	
	int token = this->_stack.top();
	this->_stack.pop();
	if (isToken(token))
	{
		int rhs = this->compute();
		int lhs = this->compute();
		return (this->op(token, lhs, rhs));
	}
	return (token - '0');
}

RPN::const_iterator	RPN::push(RPN::const_iterator it, RPN::const_iterator end)
{
	if (it != end && (isdigit(*it) || isToken(*it)))
	{
		// std::cout << *it << std::endl;
		if ((it + 1) != end && *(it + 1) != ' ')
			throw InputException();
		this->_stack.push(*it);
	}
	else
		throw InputException();

	return (it);
}


	
// Excetpion

const char*	RPN::InputException::what() const throw()
{
	return ("Bad Input");
}

const char*	RPN::DivByZeroException::what() const throw()
{
	return ("Dividing By 0");
}
const char*	RPN::ComputeException::what() const throw()
{
	return ("Compute Exception");
}