/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:03:48 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 11:55:57 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point const a(0.0f, 0.0f);
    Point const b(1.5f, 3.0f);
    Point const c(3.0f, 0.0f);
   
   { Point const p(0.5f, 0.5f);
    std::cout << bsp(a, b, c, p)<< std::endl;}
    
    
   {Point const p(4, 4);
    std::cout << bsp(a, b, c, p)<< std::endl;}

    {Point const p(3.0f, 0.0f);
    std::cout << bsp(a, b, c, p)<< std::endl;}

   {Point const p(1, 2);
    std::cout << bsp(a, b, c, p)<< std::endl;}

    {Point const p(0.75f, 1);
    std::cout << bsp(a, b, c, p)<< std::endl;}

    return (0);
}