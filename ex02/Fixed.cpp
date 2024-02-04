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

std::ostream &operator<<(std::ostream& os, Fixed const& other)
{
	os << other.toFloat();
	return (os);
}

Fixed&	Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called\n";
	setRawBits(other.getRawBits());
	return (*this);
}

bool	Fixed::operator<(Fixed const& f1)
{
	return (this->getRawBits() < f1.getRawBits());
}

bool	Fixed::operator>(Fixed const& f1)
{
	return (this->getRawBits() > f1.getRawBits());
}

bool	Fixed::operator<=(Fixed const& f1)
{
	return (this->getRawBits() <= f1.getRawBits());
}

bool	Fixed::operator>=(Fixed const& f1)
{
	return (this->getRawBits() >= f1.getRawBits());
}

bool	Fixed::operator==(Fixed const& f1)
{
	return (this->getRawBits() == f1.getRawBits());
}

bool	Fixed::operator!=(Fixed const& f1)
{
	return (this->getRawBits() != f1.getRawBits());
}

Fixed	Fixed::operator*(Fixed const& f1)
{
	return (Fixed(this->toFloat() * f1.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& f1)
{
	return (Fixed(this->toFloat() / f1.toFloat()));
}

Fixed	Fixed::operator+(Fixed const& f1)
{
	return (Fixed(this->toFloat() + f1.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& f1)
{
	return (Fixed(this->toFloat() - f1.toFloat()));
}

Fixed&	Fixed::operator++(void) //prefix
{
	fixedPointNbr += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void) //prefix
{
	fixedPointNbr -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int) //postfix
{
	Fixed	temp = *this;

	fixedPointNbr += 1;
	return (temp);
}

Fixed	Fixed::operator--(int) //postfix
{
	Fixed	temp = *this;

	fixedPointNbr -= 1;
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

/*---Functions---*/

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed&  Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}