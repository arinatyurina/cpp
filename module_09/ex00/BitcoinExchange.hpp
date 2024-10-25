/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:48:03 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/25 16:45:22 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>

struct date
{
	int	year;
	int	month;
	int	day;

	bool operator<(const date& other) const
	{
		if (year != other.year)
			return (year < other.year);
		if (month != other.month)
			return (month < other.month);
		return (day < other.day);
	}

	date& operator=(const date& other)
	{
		if (this != &other)
		{
			year = other.year;
			month = other.month;
			day = other.day;
		}
		return (*this);
	}

	bool isValidFormat(const std::string& date_str) const
	{
		if (date_str.size() != 10) return false; // Check length

		// Check for YYYY-MM-DD format
		if (date_str[4] != '-' || date_str[7] != '-')
			return false;
		for (int i = 0; i < date_str.size(); ++i) 
		{
			if (i == 4 || i == 7)
				continue;
			if (!isdigit(date_str[i]))
				return false;
		}
		return true;
	}

	bool setDate(const std::string& date_str)
	{
		if (!isValidFormat(date_str))
			return (false);

		size_t pos1 = date_str.find('-');
		size_t pos2 = date_str.find('-', pos1 + 1);
		try
		{
				year = std::stoi(date_str.substr(0, pos1));
				month = std::stoi(date_str.substr(pos1 + 1, pos2 - pos1 - 1));
				day = std::stoi(date_str.substr(pos2 + 1));
		}
		catch (...)
		{
			return (false);
		}

		if (month < 1 || month > 12 || day < 1 || day > 31)
			return (false);

		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return (false);

		if (month == 2) // February
		{
			bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
			if (day > (isLeap ? 29 : 28))
				return (false);
		}

		return (true);
	}
};

class BitcoinExchange
{
private:
	std::map<date, float>	database;

	bool	isValidDate(std::string date);
	bool	isInRangeDate(date);

	bool	isValidValue(std::string value);
	void	displayRate(date date, float price);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);

	bool	createDatabase(std::string filename);
};

#endif

/*
Maps are associative containers that store elements formed by a combination 
of a key value and a mapped value, following a specific order.

In a map, the key values are generally used to sort and uniquely identify the elements,
while the mapped values store the content associated to this key.
The types of key and mapped value may differ, and are grouped together in member type value_type,
which is a pair type combining both:
typedef pair<const Key, T> value_type;

Internally, the elements in a map are always sorted by its key following a specific
strict weak ordering criterion indicated by its internal comparison object (of type Compare).
*/