/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:39:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/08 23:48:27 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cctype>

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

//checks if a string is a double
bool	isDouble(std::string s)
{
	char* end;
	std::strtod(s.c_str(), &end);
	if (*end == '\0')
		return (true);
	return (false);
}

bool	isFloat(std::string s)
{
	if (s.back() == 'f' && isDouble(s.substr(0, s.size() - 1)))
		return (true);
	return (false);
}

bool isSpecialLiteral(std::string s)
{
	return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" ||
				s == "+inff" || s == "-inff");
}

void	handleSpecialLiteral(std:: string s)
{
	std::cout << "[char] impossible" << std::endl;
	std::cout << "[int] impossible" << std::endl;
	if (s == "nanf" || s == "+inff" || s == "-inff")
	{
		std::cout << "[float] " << s << std::endl;
		std::cout << "[double] impossible" << std::endl;
	}
	else if (s == "nan" || s == "+inf" || s == "-inf")
	{
		std::cout << "[float] impossible" << std::endl;
		std::cout << "[double] " << s << std::endl;
	}
}

void	ScalarConverter::convert(std::string s)
{
	std::cout << "<---------------------->" << std::endl;
	std::cout << "String passed as a parameter: " << s << std::endl;

	if (isSpecialLiteral(s))
	{
		handleSpecialLiteral(s);
		return;
	}

	int len = s.size();
	/*if char literal*/
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
	{
		std::cout << "[char] '" << s[0] << "'" << std::endl;
		std::cout << "[int] " << static_cast<int>(s[0]) << std::endl;
		std::cout << "[float] " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
		std::cout << "[double] " << static_cast<double>(s[0]) << std::endl;
		return;
	}

	/*if int*/
	if (num != 0 || (len == 1 && s[0] == '0'))
		std::cout << "[int] " << num << std::endl;
	else
		std::cout << "[int] is not displayable" << std::endl;

	/*float*/
	std::cout << std::fixed << std::setprecision(1); /*float to 1 decimal place*/
	if (isFloat(s))
	{
		float	f = static_cast <float> (atof(s.c_str()));
		std::cout << "[float] " << f << "f" << std::endl;
	}
	else
		std::cout << "[float] is not displayable" << std::endl;

	//double	d = static_cast <double> (atof_l(s.c_str()));
		if (isDouble(s))
	{
		char * end;
		double	f = static_cast <double> (std::strtod(s.c_str(), &end));
		std::cout << "[double] " << f << std::endl;
	}
	else
		std::cout << "[double] is not displayable" << std::endl;
}

/*
Casting Operators in C++:
* static_cast <new_type> (expression);
The static_cast operator is the most commonly used casting operator in C++. 
It performs compile-time type conversion and is mainly used 
for explicit conversions that are considered safe by the compiler. 
*/