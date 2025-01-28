/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:10:24 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/28 17:10:33 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define CHAR_MIN -128
#define CHAR_MAX 127

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <cfloat>
#include <cmath>
#include "Utils.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	virtual ScalarConverter& operator=(const ScalarConverter& other) = 0;
	/*ScalarConverter becomes an abstract base class that cannot be instantiated directly.*/
public:
	static void	convert(std::string s);
};

#endif

/*
A static_cast in C++ is a type of cast used to convert between types at compile time. 
It is one of the most common and straightforward types of casting available in C++. 
It is used when you know that the conversion between types is safe and valid, 
and you want the compiler to perform the conversion for you.
*/