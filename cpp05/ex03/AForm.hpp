/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:51:13 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/20 18:11:03 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


class AForm
{
	public:
		// Constructors
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToEx);
		AForm(const AForm &copy);
		
		// Destructor
		virtual ~AForm();
		
		// Operators
		AForm & operator=(const AForm &assign);

		//Getters
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeEx(void) const;
		std::string	getTarget(void) const;
		void		setTarget(std::string new_target);
		void		beSigned(Bureaucrat &bureaucrat);

		//Abstract functions
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToEx;
		std::string			_target;




	// Exception
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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};

};

std::ostream & operator << (std::ostream &out, const AForm &f);

#endif