/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:39:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/24 23:17:42 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTYPE_HPP
# define GETTYPE_HPP

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define UNDEFINED 4

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <limits>
# include <cmath>

int		getType(std::string toConvert);
char	checkChar(int converted);
double	checkLimit(std::string toConvert);
float	checkLimitf(std::string toConvert);

#endif