/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:31:05 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/28 17:22:25 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

//checks if a string is a double
bool	isDouble(std::string s)
{
	char* end;
	strtod(s.c_str(), &end);
	if (*end == '\0')
		return (true);
	return (false);
}

bool	isFloat(std::string s)
{
	if (!s.empty() && s[s.size() - 1] == 'f' && isDouble(s.substr(0, s.size() - 1)))
		return (true);
	return (false);
}

bool	isInt(std::string s)
{
	char *end;
	strtol(s.c_str(), &end, 10);
	if (*end == '\0')
		return (true);
	return (false);
}

/*
+inff: This represents positive infinity as a float value.
-inff: This represents negative infinity as a float value.
nan: This is a constant representing Not a Number in double-precision (double).
nanf: This is a constant representing Not a Number in single-precision (float).
*/
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
		std::cout << "[float] " << s << "f" << std::endl;
		std::cout << "[double] " << s << std::endl;
	}
}

bool isNumberInRange(const std::string &s, long min, long max)
{
	long value = atol(s.c_str());
	return (value >= min && value <= max);
}