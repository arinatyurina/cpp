/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:47:54 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/23 23:57:13 by atyurina         ###   ########.fr       */
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

bool	BitcoinExchange::makeDatabase(std::string filename)
{
	std::ifstream	ifs(filename.c_str());
	std::string	line;

	if (!ifs.is_open())
	{
		std::cerr << "Error: Could not open database." << std::endl;
		return (EXIT_FAILURE);
	}
	
	
}
