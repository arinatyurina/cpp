/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:18:41 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/20 17:18:42 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool all_spaces(const std::string& str)
{
	for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
		if (!std::isspace(*i)) {
			return (false);
		}
	}
	return (true);
}

std::string	get_input_and_check(void)
{
	std::string	input;

	std::getline(std::cin, input);
	if (std::cin.eof())
		exit_program();
	
	if (input.empty() || all_spaces(input))
	{
		std::cout << ">> Please, try again. You can not leave fields empty" << std::endl;
		input = get_input_and_check();
	}
	return (input);
}

/*std::setw(int n): Устанавливает ширину поля для следующего вывода.
std::setfill(char c): Устанавливает символ заполнения.*/
std::string format_text(const std::string &text)
{
	unsigned long width = 10;
	std::stringstream ss;
	
	if (text.length() > width)
		ss << text.substr(0, width - 1) << "."; //writing to the stream
	else
		ss << std::setw(width) << std::setfill(' ') << text;
	return ss.str(); //ss.str - getting a string from the stream
}
