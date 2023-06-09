/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:39:02 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 16:28:56 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP


struct Data
{
	Data() ;
	Data(const Data &copy);
	~Data();
	Data & operator=(const Data &assign);
	int		value;
	float	value2;
};

#endif