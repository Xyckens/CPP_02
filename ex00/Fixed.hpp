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

class Fixed
{
private:
	int	fixedPointNbr;
	static const int fractBits = 8;
public:
	Fixed();
	Fixed(const Fixed &to_copy);
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
	~Fixed();
	
};

#endif
