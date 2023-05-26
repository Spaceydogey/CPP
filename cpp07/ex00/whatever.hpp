/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:21 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/26 15:56:00 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>


template<typename T>
T const &max(T const &a, T const &b)
{
	return (b >= a ? b : a);
}

template<typename T>
T const &min(T const &a, T const &b)
{
	return (b > a ? a : b);
}

template<typename T>
void	swap(T  &a, T  &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

#endif