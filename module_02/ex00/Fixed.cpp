/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:23:56 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/02 18:26:23 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) // a default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) //a copy constructor
{
	std::cout << "Copy constructor called" << std::endl;	
}

Fixed::Fixed& operator=(const Fixed& other) //a copy assignment operator overload
{
	
}
	~Fixed(); //a destructor

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );