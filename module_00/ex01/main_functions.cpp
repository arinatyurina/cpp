/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:18:36 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/20 17:18:37 by atyurina         ###   ########.fr       */
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
	input = get_input_and_check();
	new_contact.set_first_name(input);
	std::cout << ">> Please, input last name" << std::endl;
	input = get_input_and_check();
	new_contact.set_last_name(input);
	std::cout << ">> Please, input nickname" << std::endl;
	input = get_input_and_check();
	new_contact.set_nickname(input);
	std::cout << ">> Please, input phone number" << std::endl;
	input = get_input_and_check();
 	while (input.find_first_not_of("-+ 0123456789") != std::string::npos)
	{
		std::cout << ">> Please, try again. For phone number you can only use digits" << std::endl;
		input = get_input_and_check();;
	}
	new_contact.set_phone_number(input);
	std::cout << ">> Please, input darkest secret" << std::endl;
	input = get_input_and_check();
	new_contact.set_darkest_secret(input);
	int amount = pb.getAmount();
	if (amount != 8)
		new_contact.update_contact_id(amount);
	else
	{
		pb.updateContactId();
		new_contact.update_contact_id(7);
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
		std::stringstream ss;
		ss << (pb.getAmount() - 1);
		std::string nbr = ss.str();
		std::cout << "Please, input the index to display a specific contact (0-" << nbr << ")." << std::endl;
		input = get_input_and_check();
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
			{
				std::stringstream ss;
				ss << (pb.getAmount() - 1);
				std::string nbr = ss.str();
				std::cout << "WRONG INPUT >> Index must be a number between 0 and " << nbr << '.' << std::endl;
			}
		}
		else
		{
			std::stringstream ss;
			ss << (pb.getAmount() - 1);
			std::string nbr = ss.str();
			std::cout << "WRONG INPUT >> Index must be a number between 0 and " << nbr << '.' << std::endl;
		}
	}
}