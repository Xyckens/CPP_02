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

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed pa_x = point.getX() - a.getX();
	Fixed pa_y = point.getY() - a.getY();

	Fixed pb_x = point.getX() - b.getX();
	Fixed pb_y = point.getY() - b.getY();

	bool point_ab = (b.getX() - a.getX()) * pa_y - (b.getY() - a.getY()) * pa_x > 0;
	
	if ((c.getX() - a.getX()) * pa_y - (c.getY() - a.getY()) * pa_x > 0 == point_ab)
		return (false);
	if ((c.getX() - b.getX()) * pb_y - (c.getY() - b.getY() * pb_x) > 0 != point_ab)
		return (false);
	return (true);
}

/* https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle */