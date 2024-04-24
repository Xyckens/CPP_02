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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixedPointNbr);
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called\n";
	this->fixedPointNbr = to_copy.fixedPointNbr;
}

Fixed&	Fixed::operator=(Fixed const& other)
{
	if(this == &other)
		return(*this);
	std::cout << "Copy assignment operator called\n";
	this->fixedPointNbr = other.fixedPointNbr;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
