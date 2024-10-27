/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:47:54 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/27 20:52:52 by atyurina         ###   ########.fr       */
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

	std::getline(ifs, line); //header
	while (std::getline(ifs, line))
	{
		date	_date;
		size_t position = line.find(',');
		if (position == std::string::npos) //not found
		{
			std::cerr << "Error: Invalid format in database." << std::endl;
			std::cerr << "Line:" <<  line << std::endl;
			return (false);
		}
		std::string date_str = line.substr(0, position);
		std::string rate_str = line.substr(position + 1);

		if (!_date.setDate(date_str))
		{
			std::cerr << "Error: Could not set date:" << date_str <<std::endl;
			return(false);
		}
		float rate;
		try 
		{
			rate = std::stof(rate_str);
		}
		catch (...)
		{
			std::cerr << "Error: Invalid rate format." << std::endl;
			std::cerr << "Line: " << line << std::endl;
			return (false);
		}
		std::pair<date, float>	 new_pair(_date, rate);
		database.insert(new_pair);
	}
	return (true);
}

void	BitcoinExchange::printDatabase(void)
{
		for (std::map<date, float>::iterator it = database.begin(); it != database.end(); ++it)
	{
		const date& d = it->first;
		float rate = it->second;
		std::cout << "Date: " << d.year << "-" << d.month << "-" << d.day
							<< " Rate: " << rate << std::endl;
	}
}

bool	BitcoinExchange::isInRangeDate(date _date)
{
	if (database.find(_date) != database.end())
		return (true);
	return (false);
}