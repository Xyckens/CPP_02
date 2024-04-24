/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:44:39 by fvieira           #+#    #+#             */
/*   Updated: 2023/05/14 14:44:41 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <memory>
# include <cmath>

class Fixed
{
private:
	int	fixedPointNbr;
	static const int fractBits = 8;
public:
	Fixed();
	Fixed(const Fixed &to_copy);
	Fixed(const int intNbr);
	Fixed(const float floatNbr);
	~Fixed();

	void	setRawBits(int const raw);
	int		getRawBits(void) const;

	Fixed&	operator=(Fixed const& other);
	bool	operator<(Fixed const& f1) const;
	bool	operator>(Fixed const& f1) const;
	bool	operator<=(Fixed const& f1) const;
	bool	operator>=(Fixed const& f1) const;
	bool	operator==(Fixed const& f1) const;
	bool	operator!=(Fixed const& f1) const;
	Fixed	operator*(Fixed const& f1) const;
	Fixed	operator/(Fixed const& f1) const;
	Fixed	operator-(Fixed const& f1) const;
	Fixed	operator+(Fixed const& f1) const;
	Fixed&	operator++(); //prefix
	Fixed&	operator--(); //prefix
	Fixed	operator++(int); //postfix
	Fixed	operator--(int); //postfix

	static Fixed&       max(Fixed& f1, Fixed& f2);
	static Fixed&       min(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& other);

#endif
