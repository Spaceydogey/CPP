/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:29:52 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 22:42:59 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.cpp"

class Point
{
    private :
        Fixed const _x;  
        Fixed const _y;

    public :
        Point(void);
        Point(Point const &to_cp);
        Point(float const x, float const y);
        ~Point(void);

        Point   &operator=(Point const &rhs);

};

#endif