/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:48:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/29 16:04:23 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isValidValue(std::string val_str)
{
	float	val;
	try 
	{
		val = std::stof(val_str);
	}
	catch (...)
	{
		std::cerr << "Error: Invalid value format." << std::endl;
		return (false);
	}
	if (val > 1000)
	{
		std::cerr << "Error: number is too large." << std::endl;
		return (false);
	}
	else if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	return (true);
}

date findClosestDate(date _date, BitcoinExchange& BitExchange)
{
	std::map<date, float>::iterator it = BitExchange.database.lower_bound(_date);
	
	// found an exact match, return it directly
	if (it != BitExchange.database.end() && !(it->first < _date) && !(_date < it->first))
			return it->first;
	// there’s no earlier date to use, so we return the first date in the map.
	if (it == BitExchange.database.begin())
			return it->first;
	// move back to the previous element to ensure we get the closest date that is still less than `_date`.
	--it;
	return it->first;
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
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
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
		date	closest_date = findClosestDate(_date, BitExchange);
		_date.outputDate();
		float rate = BitExchange.database[closest_date];
		float val_mul_rate = val * rate;
		std::cout << " => "<< val << " = " << val_mul_rate << std::endl;
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

	/*map_name.lower_bound(key) 
	The function returns an iterator pointing to the key in the map container which is equivalent to k passed in the parameter.
	In case k is not present in the map container, the function returns an iterator pointing to the immediate next elementwhich is just greater than k.
	If the key passed in the parameter exceeds the maximum key in the container, the returned iterator will point to map::end(),
	indicating that no elements in the map have a key greater than or equal to the passed key.*/