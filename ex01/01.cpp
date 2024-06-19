/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:58:19 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/05 16:58:21 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

const Contact& PhoneBook::getContact(int index) const {
	return Contacts[index];
}

int		PhoneBook::getAmount(void)
{
	return (Amount);
}

void	PhoneBook::updateContactId(void)
{
	for (int i = 7; i >= 0; i--)
		Contacts[i].id -= 1;
}

int		PhoneBook::getNext(void)
{
	return (Next);
}

int PhoneBook::ContactIndexById(int id)
{
	int	amount = Amount;
	int index = 0;

	if (amount == 0)
		return (-1);
	while (amount > 0)
	{
		if (Contacts[index].id == id)
			return (index);
		index = (index + 1) % 8;
		amount--;
	}
	return (-1);
}
		
void	PhoneBook::add(const Contact& contact)
{
	if (Amount < 8)
		Amount++;
	Contacts[Next] = contact;
	Next = (Next + 1) % 8;
}

std::string format_text(const std::string &text)
{
	unsigned long width = 10;
	if (text.length() > width)
		return text.substr(0, width - 1) + ".";
	else 
		return std::string(width - text.length(), ' ') + text;
}

void	Contact::print_contact(void)
{
	std::cout << "First_name: " << First_name << std::endl;
	std::cout << "Last_name: " << Last_name << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone_number: " << Phone_number << std::endl;
	std::cout << "Darkest_secret: " << Darkest_secret << std::endl;
}

void	Contact::print_contact_column(void)
{
	std::cout << '|' << format_text(std::to_string(id)) \
	<< '|' << format_text(First_name) \
	<< '|' << format_text(Last_name) \
	<< '|' << format_text(Nickname) \
	<< '|' << std::endl; 
}

void	Contact::set_first_name(const std::string& name)
{
	First_name = name;
}

void	Contact::set_last_name(const std::string&surname)
{
	Last_name = surname;
}

void	Contact::set_nickname(const std::string&nick)
{
	Nickname = nick;
}
void	Contact::set_phone_number(const std::string&phone)
{
	Phone_number = phone;
}

void	Contact::set_darkest_secret(const std::string&secret)
{
	Darkest_secret = secret;
}
