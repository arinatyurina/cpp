/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:53:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/06 18:53:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
	PhoneBook	pb;
	std::string	input;

	std::cout << "Hello User! Welcome to Awesome PhoneBook! " << std::endl;
	std::cout << "On program start-up, the phonebook is empty.\n>> The program only accepts ADD, SEARCH and EXIT." << std::endl;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit_program();
		if (input == "ADD")
			add_contact(pb);
		else if (input == "SEARCH")
			search_contact(pb);
		else if (input == "EXIT")
			exit_program();
		else
			std::cout << ">> The program only accepts ADD, SEARCH and EXIT.\nAny other input is discarded." << std::endl;
		std::cout << ">> The program only accepts ADD, SEARCH and EXIT." << std::endl;
	}
}
