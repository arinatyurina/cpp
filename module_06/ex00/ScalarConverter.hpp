/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:10:24 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/28 13:05:39 by atyurina         ###   ########.fr       */
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
Static member functions are class-level functions that are not tied to any instance.
They can access only static members of the class.
Useful for operations that are not specific to an object but relevant to the class as a whole, 
providing a way to encapsulate behavior at the class level rather than the instance level.
*/