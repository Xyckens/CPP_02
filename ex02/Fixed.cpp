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
	setRawBits(intNbr * (1 << Fixed::fractBits));
}

Fixed::Fixed(const float floatNbr)
{
	std::cout << "Float constructor called\n";
	setRawBits(roundf(floatNbr * (1 << Fixed::fractBits)));
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


/* ---OPERATORS---*/

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

Fixed&	Fixed::operator+(Fixed const& f1, Fixed const& f2)
{
	return (toFloat(f1 + f2));
}

Fixed&	Fixed::operator-(Fixed const& f1, Fixed const& f2)
{
	return (toFloat(f1 - f2));
}

Fixed&	Fixed::operator++() //prefix
{
	int epsilon = 1;

	fixedPointNbr += toFloat(epsilon);
	return (*this);
}

Fixed&	Fixed::operator--() //prefix
{
	int epsilon = 1;

	fixedPointNbr -= toFloat(epsilon);
	return (*this);
}

Fixed	Fixed::operator++(int) //postfix
{
	int		epsilon = 1;
	Fixed	temp = *this;

	fixedPointNbr += toFloat(epsilon);
	return (temp);
}

Fixed	Fixed::operator--(int) //postfix
{
	int		epsilon = 1;
	Fixed	temp = *this;

	fixedPointNbr -= toFloat(epsilon);
	return (temp);

}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNbr / (float)(1 << Fixed::fractBits));
}

int		Fixed::toInt(void) const
{
	return(this->fixedPointNbr >> Fixed::fractBits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}