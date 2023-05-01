/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:05:29 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 14:24:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		// Constructors
		MateriaSource(void);
		MateriaSource(const MateriaSource &to_cp);
		
		// Destructor
		~MateriaSource(void);
		
		// Operators
		MateriaSource & operator=(const MateriaSource &rhs);
        
        //Member Functions
		virtual void		learnMateria(AMateria *m);
        virtual AMateria*	createMateria(std::string const & type);
		
	private:
        int         _size;
        AMateria    *_list[];
		
};

#endif