/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:48:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/27 21:38:28 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isValidValue(std::string val_str)
{
	try 
	{
		float val = std::stof(val_str);
		val++;
	}
	catch (...)
	{
		std::cerr << "Error: Invalid value format." << std::endl;
		return (false);
	}
	return (true);
}

void	outputInfo(std::ifstream &ifs, BitcoinExchange BitExchange)
{
	std::string line;

	std::getline(ifs, line); //header
	while (std::getline(ifs, line))
	{
		size_t position = line.find("|");
		if (position == std::string::npos) //not found
		{
			std::cerr << "Error: Invalid format in database." << std::endl;
			std::cerr << "Line:" <<  line << std::endl;
			return;
		}
		std::string date_str = line.substr(0, position - 1);
		std::string val_str = line.substr(position + 2);

		date	_date;
		if (!_date.setDate(date_str))
		{
			std::cerr << "Error: bad input " << date_str <<std::endl;
			continue;
		}

		if (!isValidValue(val_str))
			continue;
		float val = std::stof(val_str);
		if (BitExchange.database.find(_date) == BitExchange.database.end())
		{
			//if not found>>> get the closest date (in the past)
			std::cout << "get the closest date..." << std::endl;
		}
		else
		{
			_date.outputDate();
			float rate = BitExchange.database[_date];
			float val_mul_rate = val * rate;
			std::cout << " " << val_mul_rate << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	std::string	infile = argv[1];
	std::ifstream	ifs(infile.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: File doesn't exist/permission denied." << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	BitExchange;
	if (!BitExchange.createDatabase("data.csv"))
	{
		std::cerr << "Error: Could not create database." << std::endl;
		return (EXIT_FAILURE);
	}

	//BitExchange.printDatabase();
	outputInfo(ifs, BitExchange);
}