/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:53:40 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 14:54:43 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		// Constructors
		IMateriaSource() {};
		IMateriaSource(const IMateriaSource &to_cp) {(void)to_cp;};
		
		// Destructor
		virtual ~IMateriaSource() {};
		
		// Operators
		IMateriaSource & operator=(const IMateriaSource &rhs) {(void)rhs;return (*this);};
		
		//Member Functions
		virtual void    	learnMateria(AMateria *m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
	private:
		
};

#endif