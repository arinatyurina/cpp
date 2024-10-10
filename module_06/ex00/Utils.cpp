/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:31:05 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/10 23:35:09 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

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

bool	isInt(std::string s)
{
	char *end;
	std::strtol(s.c_str(), &end, 10);
	if (*end == '\0')
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
		std::cout << "[float] " << s << "f" << std::endl;
		std::cout << "[double] " << s << std::endl;
	}
}

bool isNumberInRange(const std::string &s, long min, long max)
{
	long value = std::atol(s.c_str());
	return (value >= min && value <= max);
}