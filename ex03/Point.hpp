/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:24:14 by fvieira           #+#    #+#             */
/*   Updated: 2023/05/23 14:24:16 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float f1, const float f2);
	Point(const Point &to_copy);

	Point&			operator=(Point const& other);
	static Fixed	getTriangleArea(Point const a, Point const b, Point const c);

	void	setX(Fixed const x);
	void	setY(Fixed const y);

	Fixed	getX() const;
	Fixed	getY() const;

	~Point();	
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
