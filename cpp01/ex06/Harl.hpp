/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:22:05 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/20 19:29:17 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
private:
	void 	(Harl::*_fct[4])(void) const;
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;

public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level) const;
};



#endif