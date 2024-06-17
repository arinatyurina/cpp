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


void	PhoneBook::add(const Contact& contact)
{
	if (Amount < 8)
	{
		Contacts[Next].id = Next;
		Amount++;
	}
	else
	{
		Contacts[Next].id = 7;
		for (int i = 1; i < 8; i++)
			Contacts[i].id -= 1;
	}
	Contacts[Next] = contact;
	Next = (Next + 1) % 8;
}

void	PhoneBook::search(void)
{

}

void	Contact::print_contact(void)
{
	std::cout << First_name << std::endl;
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
