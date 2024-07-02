/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:08:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/02 18:25:04 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ieee754.h>
#include <iostream>

class Fixed
{
private:
	int	FixedPoint;
	static const int	NumFractionalBits = 8;
public:
	Fixed(); // a default constructor
	Fixed(const Fixed& other); //a copy constructor
	Fixed& operator=(const Fixed& other); //a copy assignment operator overload
	~Fixed(); //a destructor

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif