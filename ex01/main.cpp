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

void	add_contact(PhoneBook pb)
{
	Contact		new_contact;
	std::string	input;

	std::cout << "Input the information of the new contact" << std::endl;
	std::cout << ">> Please, input first name" << std::endl;
	std::cin >> input;
	new_contact.set_first_name(input);
	std::cout << ">> Please, input last name" << std::endl;
	std::cin >> input;
	new_contact.set_last_name(input);
	std::cout << ">> Please, input nickname" << std::endl;
	std::cin >> input;
	new_contact.set_nickname(input);
	std::cout << ">> Please, input phone number" << std::endl;
	std::cin >> input;
	new_contact.set_phone_number(input);
	std::cout << ">> Please, input darkest secret" << std::endl;
	std::cin >> input;
	new_contact.set_darkest_secret(input);
	pb.add(new_contact);
	std::cout << "New contact was successfully added ✔" << std::endl;
}

void	search_contact(PhoneBook pb)
{
	std::string	input;

	while (1)
	{
		std::cout << "Please, input the index to display a specific contact (0-7)." << std::endl;
		std::cin >> input;
		if (input.length() == 1 && std::isdigit(input[0]))
		{
			int index = input[0] - '0';
			if (index >= 0 && index <= 7)
			{
				Contact chosen_contact;
				chosen_contact = pb.getContact(index);
				chosen_contact.print_contact();
			}
			else
				std::cout << "Index must be a number between 0 and 7." << std::endl;
		}
	}
}

int main(void)
{
	PhoneBook	pb;
	std::string	input;

	std::cout << "Hello User! Welcome to Awesome PhoneBook! " << std::endl;
	std::cout << "On program start-up, the phonebook is empty.\n>> The program only accepts ADD, SEARCH and EXIT." << std::endl;
	while (1)
	{
		std::cin >> input;
		if (input == "ADD")
			add_contact(pb);
		else if (input == "SEARCH")
			search_contact(pb);
		else if (input == "EXIT")
		{
			std::cout << "You want to EXIT" << std::endl;
			return (0);
		}
		else
			std::cout << ">> The program only accepts ADD, SEARCH and EXIT.\nAny other input is discarded." << std::endl;
	}
}
