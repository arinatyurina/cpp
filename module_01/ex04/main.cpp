/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:45:56 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/25 17:26:41 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/**
 * Task:
 * Open the file <filename> and copies its content into a new file
 * <filename>.replace, replacing every occurrence of s1 with s2.
 * 
*/

std::string	get_text(std::ifstream& ifs, std::string s1, std::string s2)
{
	std::string	text;
	std::string	line;

	while (std::getline(ifs, line))
		text.append(line).append("\n");
	if (text.find(s1) == std::string::npos)
		return ("");
	int i = 0;
	int	p;
	while (true)
	{
		if (text.find(s1) != std::string::npos)

	}
}

int	out_file(std::ifstream &ifs, std:: string filename, std::string s1, std::string s2)
{
	std::ofstream	ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error while creating the outfile" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string	str;
	str = get_text(ifs, s1, s2);
	ifs.close();
	ofs.close();
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "This program accepts only three parameters:" << std::endl;
		std::cout << " a filename and two strings, s1 and s2" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string	infile = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
/*
 * .c_str :  This method is compatible with the C++98 standard, 
 * where ifstream constructors only accepted C-style strings (const char*).
 */
	std::ifstream	ifs(infile.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error while opening the infile" << std::endl;
		return (EXIT_FAILURE);
	}
	int ret; 
	ret = out_file(ifs, infile, s1, s2);
	return (ret);
}