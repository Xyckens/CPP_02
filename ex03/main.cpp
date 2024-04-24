/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:44:23 by fvieira           #+#    #+#             */
/*   Updated: 2023/05/14 14:44:25 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	Point a(12.58, 3.53);
    Point b(10.38, 5.41);
    Point c(8.98, 3.63);
    Point pointOutClose(11.84,4.22);
    Point pointOutFar(7.3,5.47);
    Point pointInMidle(10.7,4.13);
    Point pointInPeripheral(9.412,3.823);
    Point pointEdge(11.18829164644,3.5686577173323);
    
    std::cout << "Points outside of triangle: " << "close - " << bsp(a, b, c, pointOutClose)
    << "; far - " << bsp(a, b, c, pointOutClose) << std::endl;
    std::cout << "Points inside of triangle: " << "midle - " << bsp(a, b, c, pointInMidle)
    << "; peripheral - " << bsp(a, b, c, pointInPeripheral) << std::endl;
    std::cout << "Point edge of triangle: " << bsp(a, b, c, pointEdge) << std::endl;
    std::cout << "Point vertix of triangle: " << bsp(a, b, c, a) << std::endl;
    std::cout << "Invalid Triangle: " << bsp(a, a, a, b) << std::endl;
    return 0;
}
