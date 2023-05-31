#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <algorithm>
# include <stack>


template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Constructors
		MutantStack(){};
		MutantStack(const MutantStack &copy): std::stack<T>(copy){};
		
		// Destructor
		~MutantStack(){};
		
		// Operators
		MutantStack & operator=(const MutantStack &assign)
		{
			std::stack<T>::operator=(assign);
			return (*this);
		};
		
		typedef typename  MutantStack<T>::stack::container_type::iterator iterator;
		typedef typename  MutantStack<T>::stack::container_type::const_iterator const_iterator;
		typedef typename  MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		typedef typename  MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator				begin(void)
		{
			return (this->c.begin());
		}
		const_iterator			begin(void) const
		{
			return (this->c.begin());
		}
		const_reverse_iterator	rbegin(void) const
		{
			return (this->c.rbegin());
		}
		reverse_iterator		rbegin(void) 
		{
			return (this->c.rbegin());
		}
		iterator				end(void)
		{
			return (this->c.end());
		}
		const_iterator			end(void) const
		{
			return (this->c.end());
		}
		const_reverse_iterator	rend(void) const
		{
			return (this->c.rend());
		}
		reverse_iterator		rend(void)
		{
			return (this->c.rend());
		}
	private:
		
};

#endif