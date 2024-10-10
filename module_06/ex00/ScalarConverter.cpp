/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:39:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/10 23:40:35 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

void	ScalarConverter::convert(std::string s)
{
	if (isSpecialLiteral(s))
	{
		handleSpecialLiteral(s);
		return;
	}

	/*if char literal*/
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
	{
		std::cout << "char literal" << std::endl;
		std::cout << "[char] '" << s[0] << "'" << std::endl;
		std::cout << "[int] " << static_cast<int>(s[0]) << std::endl;
		std::cout << "[float] " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
		std::cout << "[double] " << static_cast<double>(s[0]) << std::endl;
		return;
	}

	/*if int*/
	char* end;
	if (isInt(s))
	{
		std::cout << "int literal" << std::endl;
		int num =  static_cast<int>(std::atol(s.c_str()));
		if (num < INT_MIN || num > INT_MAX || !isNumberInRange(s, INT_MIN, INT_MAX))
		{
			std::cout << "[char] impossible" << std::endl;
			std::cout << "[int] impossible" << std::endl;
			std::cout << "[float] impossible" << std::endl;
			std::cout << "[double] impossible" << std::endl;
			return;
		}
		else 
		{
			if (num >= CHAR_MIN && num <= CHAR_MAX && std::isprint(static_cast<char>(num)))
					std::cout << "[char] '" << static_cast<char>(num) << "'" << std::endl;
			else
					std::cout << "[char] is not displayable" << std::endl;
			std::cout << "[int] " << num << std::endl;
			std::cout << "[float] " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
			std::cout << "[double] " << static_cast<double>(num) << std::endl;
			return;
		}
	}

	/*if float*/
	std::cout << std::fixed << std::setprecision(1); /*float to 1 decimal place*/
	if (isFloat(s))
	{
		std::cout << "float literal" << std::endl;
		int num =  static_cast<int>(std::atol(s.c_str()));
		float	f = static_cast <float> (atof(s.c_str()));
				if (num >= CHAR_MIN && num <= CHAR_MAX && std::isprint(static_cast<char>(num)))
				std::cout << "[char] '" << static_cast<char>(num) << "'" << std::endl;
		else
				std::cout << "[char] is not displayable" << std::endl;
		if (f >= INT_MIN && f <= INT_MAX)
				std::cout << "[int] " << static_cast<int>(f) << std::endl;
		else
				std::cout << "[int] impossible" << std::endl;
		std::cout << "[float] " << f << "f" << std::endl;
		std::cout << "[double] " << static_cast<double>(f) << std::endl;
		return;
	}

	/*if double*/
		if (isDouble(s))
	{
		std::cout << "double literal" << std::endl;
		double d = std::strtod(s.c_str(), &end);
		if (*end == '\0') // Successful conversion
		{
			if (std::fabs(d) > DBL_MAX || std::log10(std::fabs(d)) > 15) 
			{
				std::cout << "[char] impossible" << std::endl;
				std::cout << "[int] impossible" << std::endl;
				std::cout << "[float] impossible" << std::endl;
				std::cout << "[double] impossible (precision lost)" << std::endl;
			}
			else
			{
			if (d >= CHAR_MIN && d <= CHAR_MAX && std::isprint(static_cast<char>(d)))
					std::cout << "[char] '" << static_cast<char>(d) << "'" << std::endl;
			else
					std::cout << "[char] is not displayable" << std::endl;
			if (d >= INT_MIN && d <= INT_MAX)
					std::cout << "[int] " << static_cast<int>(d) << std::endl;
			else
					std::cout << "[int] impossible" << std::endl;
			std::cout << "[float] " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "[double] " << d << std::endl;
			}
		}
		else
			std::cout << "Unsuccessful conversion" << std::endl;
		return;
	}
	std::cout << "This string can not be converted :c" << std::endl;
}

/*
Casting Operators in C++:
* static_cast <new_type> (expression);
The static_cast operator is the most commonly used casting operator in C++. 
It performs compile-time type conversion and is mainly used 
for explicit conversions that are considered safe by the compiler. 
*/