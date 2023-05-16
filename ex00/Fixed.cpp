/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:44:48 by fvieira           #+#    #+#             */
/*   Updated: 2023/05/14 14:44:55 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNbr = raw;
}

Fixed::Fixed(void)
{
	Fixed::setRawBits(0);
	std::cout << "Default constructor called\n";
}

void	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n";
	std::cout << this->fixedPointNbr << std::endl;
}

Fixed(const Fixed &to_copy)
{
	
}