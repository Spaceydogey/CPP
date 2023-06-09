/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:36:10 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 15:08:44 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	public:
		// Constructors
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);
		
        // Destructor
		virtual ~AMateria();
		
		// Operators
		AMateria & operator=(const AMateria &assign);
		
        //Member functions
        std::string const & getType() const; //returns the materia type

        //Methodes
        virtual AMateria *	clone () const = 0;
		virtual	void		use(ICharacter& target);
		
	protected:
        //Atributes
        std::string const   _type;
};

#endif