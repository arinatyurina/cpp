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

void	exit_program(void)
{
	std::cout << "You exited the program. Goodbye!" << std::endl;
	exit (EXIT_SUCCESS);
}

void	add_contact(PhoneBook &pb)
{
	Contact		new_contact;
	std::string	input;

	std::cout << "Input the information of the new contact" << std::endl;
	std::cout << ">> Please, input first name" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	new_contact.set_first_name(input);
	std::cout << ">> Please, input last name" << std::endl;
	std::getline(std::cin, input);
	new_contact.set_last_name(input);
	std::cout << ">> Please, input nickname" << std::endl;
	std::getline(std::cin, input);
	new_contact.set_nickname(input);
	std::cout << ">> Please, input phone number" << std::endl;
	std::getline(std::cin, input);
	new_contact.set_phone_number(input);
	std::cout << ">> Please, input darkest secret" << std::endl;
	std::getline(std::cin, input);
	new_contact.set_darkest_secret(input);
	int amount = pb.getAmount();
	if (amount != 8)
		new_contact.id = amount;
	else
	{
		pb.updateContactId();
		new_contact.id = 7;
	}
	pb.add(new_contact);
	std::cout << "New contact was successfully added ✔" << std::endl;
}

void	display_contactlist(PhoneBook pb)
{
	int i;

	i = pb.getAmount();
	if (i != 0)
	{
		std::cout << '|' << format_text("Index") << '|' << format_text("First name") \
		<< '|' << format_text("Last name") << '|' << format_text("Nickname") << '|' << std::endl; 
		Contact contact;
		for (int x = 0; x < i; x++)
		{
			contact = pb.getContact(x);
			contact.print_contact_column();
		}
	}
}

void	search_contact(PhoneBook &pb)
{
	std::string	input;

	display_contactlist(pb);
	if (pb.getAmount() == 0)
	{
		std::cout << "You do not have any contacts yet." <<std::endl;
		return;
	}
	while (1)
	{
		std::cout << "Please, input the index to display a specific contact (0-" << std::to_string(pb.getAmount() - 1) << ")." <<std::endl;
		std::cin >> input;
		if (input == "EXIT")
			exit (EXIT_SUCCESS) ;
		if (input.length() == 1 && std::isdigit(input[0]))
		{
			int index = input[0] - '0';
			if (index >= 0 && index <= pb.getAmount() - 1)
			{
				Contact chosen_contact;
				int i = pb.ContactIndexById(index);
				if (i != -1)
				{
					chosen_contact = pb.getContact(i);
					chosen_contact.print_contact();
					break;
				}
				else
					std::cout << "Contact not found."<< std::endl;
			}
			else
				std::cout << "WRONG INPUT >> Index must be a number between 0 and " << std::to_string(pb.getAmount() - 1) << '.' <<std::endl;
		}
		else
			std::cout << "WRONG INPUT >> Index must be a number between 0 and " << std::to_string(pb.getAmount() - 1) << '.' <<std::endl;
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
			exit_program();
		else
			std::cout << ">> The program only accepts ADD, SEARCH and EXIT.\nAny other input is discarded." << std::endl;
	}
}
