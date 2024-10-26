/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:48:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/27 00:30:44 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// void	outputInfo(std::ifstream &ifs, BitcoinExchange &BitExchange)
// {
// 	std::string line;

// 	while (std::getline(ifs, line))
// 	{
// 		std::cout << line << std::endl;
// 	}
// }

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

	BitExchange.printDatabase();
	//outputInfo(ifs, BitExchange);
}