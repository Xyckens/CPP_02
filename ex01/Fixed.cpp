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

Fixed::Fixed(const int intNbr)
{
	std::cout << "Int constructor called\n";
	setRawBits(intNbr);
}

Fixed::Fixed(const float floatNbr)
{
	std::cout << "Float constructor called\n";
	setRawBits(static_cast<int>(floatNbr));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixedPointNbr);
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called\n";
	setRawBits(to_copy.fixedPointNbr);
}

Fixed&	Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called\n";
	setRawBits(other.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream& os, Fixed const& other)
{
	os << other.toFloat();
	return (os);

}

float	Fixed::toFloat(void) const
{
	return(static_cast<int>(this->fixedPointNbr));
}

int		Fixed::toInt(void) const
{
	return(this->fixedPointNbr);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}