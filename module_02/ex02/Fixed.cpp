/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:23:56 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/04 20:14:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : RawBits(0) // a default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() //a destructor
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) : RawBits(other.RawBits) //a copy constructor (new instance is created)
{
	std::cout << "Copy constructor called" << std::endl;
//	this->RawBits = other.getRawBits();
}

//shifting the integer to the left by the number of fractional bits and store it in RawBits
Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	RawBits = integer << NumFractionalBits; // integer << 8 is equivalent to integer * 256 (2^8 = 256)
}

/**
 * Преобразование чисел с плавающей точкой в числа с фиксированной точкой 
 * включает масштабирование числа в 2, возведенном в степень формата Q 
 * (число дробных битов), с последующим округлением до ближайшего целого числа:
 * Число с фиксированной точкой=round(Число с плавающей точкой×2^Q) 
 * 2^Q это сдвиг на количество битов, в нашем случае 8
*/
Fixed::Fixed(const float FloatingPoint)
{
	std::cout << "Float constructor called" << std::endl;
	RawBits = roundf(FloatingPoint * (1 << NumFractionalBits));
}

float	Fixed::toFloat( void ) const
{
	return (roundf(RawBits) / (1 << NumFractionalBits));
}
int		Fixed::toInt( void ) const
{
	return (RawBits >> NumFractionalBits); // RawBits >> 8 is equivalent to RawBits / 256
}

Fixed& Fixed::operator=(const Fixed& other) //a copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		RawBits = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat(); //<< "    " <<fixed.getRawBits(); // initial value * 2^8
	return (stream);
}

int		Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (RawBits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	RawBits = raw;
}


/**
 * Comparison operators
*/

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->RawBits > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->RawBits < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->RawBits >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->RawBits <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->RawBits == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->RawBits != other.getRawBits());	
}

/**
 * Arithmetic operators
*/

Fixed	Fixed::operator+(const Fixed & other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed & other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed & other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed & other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

/**
 * Increment/decrement
 * 'Post' means after - that is, 
 * the increment is done after the variable is read. 
 * 'Pre' means before - so the variable value 
 * is incremented first, then used in the expression. 
*/

//pre-incremention
Fixed&	Fixed::operator++(void)
{
	this->RawBits += 1;
	return (*this);
}

//post-incremention
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->RawBits += 1;
	return (tmp); 
}

//pre-decrement
Fixed&	Fixed::operator--(void)
{
	this->RawBits -= 1;
	return (*this);
}

//post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->RawBits -= 1;
	return (tmp); 
}

//min/const min/max/const max

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}


const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
