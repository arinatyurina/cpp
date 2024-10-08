/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:10:24 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/08 14:01:36 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	virtual ScalarConverter& operator=(const ScalarConverter& other) = 0;
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