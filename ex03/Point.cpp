/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:24:04 by fvieira           #+#    #+#             */
/*   Updated: 2023/05/23 14:24:06 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	Point::setX(Fixed const x)
{
	(Fixed) this->x = x;
}

void	Point::setY(Fixed const y)
{
	(Fixed) this->y = y;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

Point::Point()
{
	this->setX(0);
	this->setY(0);
}

Point::Point(const float f1, const float f2)
{
	this->setX(f1);
	this->setY(f2);
}

Point::Point(const Point &to_copy)
{
	this->setX(to_copy.getX());
	this->setY(to_copy.getY());
}

Point&	Point::operator=(Point const& other)
{
	setX(other.getX());
	setY(other.getY());
	return (*this);
}

Fixed Point::getTriangleArea(Point const a, Point const b, Point const c)
{
    Fixed term1 = Fixed(a.x) * (b.y - c.y);
    Fixed term2 = Fixed(b.x) * (c.y - a.y);
    Fixed term3 = Fixed(c.x) * (a.y - b.y);

    Fixed area = (term1 + term2 + term3) / Fixed(2);

    if (area < 0)
        area = area * Fixed(-1);

    return area;
}

Point::~Point()
{
	//std::cout << "Destroyed\n";
}	
