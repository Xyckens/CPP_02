/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:24:30 by fvieira           #+#    #+#             */
/*   Updated: 2023/05/23 14:24:31 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


float   roundTwoDecimalPlaces(float number)
{
    return roundf(number * 100.0) / 100.0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area;

    area = Point::getTriangleArea(a, b, c);
    if(roundTwoDecimalPlaces(area.toFloat()) == 0)
        return(false);
    Fixed area1 = Point::getTriangleArea(a, b, point);
    Fixed area2 = Point::getTriangleArea(a, point, c);
    Fixed area3 = Point::getTriangleArea(point, b, c);
    if(roundTwoDecimalPlaces(area1.toFloat()) == 0 || 
        roundTwoDecimalPlaces(area2.toFloat())== 0 ||
            roundTwoDecimalPlaces(area3.toFloat())== 0)
                return(false);
    Fixed sum = area1 + area2 + area3;
    if(roundTwoDecimalPlaces(area.toFloat()) == roundTwoDecimalPlaces(sum.toFloat()))
        return(true);
    return(false);
}
