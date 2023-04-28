/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:14:29 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 14:52:39 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);
		// Member Funtions
		std::string	getIdea(int id) const;
		int			setIdea(std::string newIdea, int id);
		int			delIdea(int id);

		
	private:
		std::string _ideas[100];
		
};

#endif