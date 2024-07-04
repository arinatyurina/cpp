/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:08:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/04 17:42:02 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ieee754.h>
#include <iostream>
#include <cmath> //float roundf (float x);
//Returns the integral value that is nearest to x, 
//with halfway cases rounded away from zero.

class Fixed
{
private:
	int	RawBits;
	static const int	NumFractionalBits = 8;
public:
	/// Canonical stuff:
	Fixed(); // a default constructor
	Fixed(const Fixed& other); //a copy constructor
	Fixed& operator=(const Fixed& other); //a copy assignment operator overload
	~Fixed(); //a destructor

	Fixed(const int integer); //converts integer to the corresponding fixed-point value
	Fixed(const float FloatingPoint); //converts floating point to fixed point

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif