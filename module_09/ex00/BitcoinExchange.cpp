/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:47:54 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/25 16:45:33 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->database = other.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		database = other.database;
	return (*this);
}

	bool	isValidDate(std::string date);
	bool	isValidValue(std::string value);
	void	displayRate(date date, float price);

bool	BitcoinExchange::createDatabase(std::string filename)
{
	std::ifstream	ifs(filename.c_str());
	std::string	line;

	if (!ifs.is_open())
	{
		std::cerr << "Error: Could not open database." << std::endl;
		return (false);
	}

	while (std::getline(ifs, line))
	{
		date	date;
		size_t position = line.find(',');
		if (position == std::string::npos) //not found
		{
			std::cerr << "Error: Invalid format in database." << std::endl;
			std::cerr << "Line:" <<  line << std::endl;
			return (false);
		}
		std::string date_str = line.substr(0, position);
		std::string rate_str = line.substr(position + 1);

		if (!date.setDate(date_str));
			return(false);

		float rate;
		try 
		{
			rate = std::stof(rate_str);
		}
		catch (...)
		{
			std::cerr << "Error: Invalid rate format." << std::endl;
			std::cerr << "Line: " << line << std::endl;
			return false;
		}
		
	}
}
