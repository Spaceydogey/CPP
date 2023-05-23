/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:21:58 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/23 14:18:57 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		
		// Destructor
		virtual ~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);

		//Getters
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		promote(void);
		void		demote(void);
		
	private:
		std::string	const _name;
		int			_grade;
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};
		
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &b);

#endif