/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:48:03 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/23 22:56:59 by atyurina         ###   ########.fr       */
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
};

class BitcoinExchange
{
private:
	std::map<date, float>	database;

	bool	isValidDate(std::string date);
	bool	isValidValue(std::string value);
	void	displayRate(date date, float price);

	bool	makeDatabase(std::string filename);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);
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