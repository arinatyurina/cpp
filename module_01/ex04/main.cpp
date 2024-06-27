/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:45:56 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/27 15:57:49 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/**
 * Task:
 * Open the file <filename> and copies its content into a new file
 * <filename>.replace, replacing every occurrence of s1 with s2.
 * 
*/

std::string modify_text(std::ifstream& ifs, const std::string& s1, const std::string& s2)
{
    std::string text;
    std::string line;

    while (std::getline(ifs, line))
        text += line + "\n";
    size_t index = text.find(s1);
    if (index == std::string::npos)
        return text;
    int skip = 0;
    while ((index = text.find(s1, skip)) != std::string::npos)
    {
        text.erase(index, s1.length());
        text.insert(index, s2);
        skip = index + s2.length();
    }
    return text;
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
	str = modify_text(ifs, s1, s2);
	ofs << str;
	ifs.close();
	ofs.close();
	return (EXIT_SUCCESS);
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

	std::ifstream	ifs(infile.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error while opening the infile" << std::endl;
		return (EXIT_FAILURE);
	}
	int ret = out_file(ifs, infile, s1, s2);
	if (ret == 0)
		std::cout << "Done" <<std::endl;
	return (ret);
}

/*
 * The c_str() method converts a string to an array of characters with a null character at the end
 *  .c_str :  This method is compatible with the C++98 standard, 
 * where ifstream constructors only accepted C-style strings (const char*).
 * 
 * ifs: It represents the file stream associated with the file specified by infile. 
 * The ifs object provides various methods to read data from the file, but it does not itself contain the text of the file.
 * It is not a string or variable that directly holds the file's contents. 
 * Instead, it is a file stream object used to read data from the file.
*/