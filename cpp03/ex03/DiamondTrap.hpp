/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:50:39 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/26 19:07:17 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, ScavTrap
{

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const & to_cp );
		~DiamondTrap();
		DiamondTrap &			operator=( DiamondTrap const & rhs );
		using ScavTrap::attack;
		void			whoAmI(void) const;


	private:
		std::string	_name;
		
};

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i );

#endif 