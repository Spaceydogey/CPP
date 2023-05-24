/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkChar.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:40:02 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/24 22:49:59 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.hpp"

char	checkChar(int converted)
{
	int	check;
	
	if (converted > 0 && converted < 128 && isprint(converted))
		check = static_cast<char>(converted);
	else 
		check = 0;
	return (check);
}
