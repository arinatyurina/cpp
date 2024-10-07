/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:39:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/07 23:57:27 by atyurina         ###   ########.fr       */
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
	/*char*/
	int num = atoi(s.c_str());
	if (num >= 0 && num <= 9)
		std::cout << "[char] " << static_cast <char> (num) << std::endl;
	else
		std::cout << "[char] is not displayable" << std::endl;
	
	long int	i = static_cast <int> (atoi(s.c_str()));
	float	f = static_cast <float> (atof(s.c_str()));
	double	d = static_cast <double> (atof_l(s.c_str()));
}

/*
Casting Operators in C++:
1) static_cast <new_type> (expression);
The static_cast operator is the most commonly used casting operator in C++. 
It performs compile-time type conversion and is mainly used 
for explicit conversions that are considered safe by the compiler. 
2)
*/