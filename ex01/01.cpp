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
	{
		int old_id;
		old_id = Contacts[i].get_contact_id();
		Contacts[i].update_contact_id(old_id - 1);
	}
}

int		PhoneBook::getNext(void)
{
	return (Next);
}

int PhoneBook::ContactIndexById(int id)
{
	int	amount = Amount;
	int index = 0;
	int	c_id;
	if (amount == 0)
		return (-1);
	while (amount > 0)
	{
		c_id = Contacts[index].get_contact_id();
		if (c_id == id)
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
	std::stringstream ss;
	ss << id;
	std::string nbr = ss.str();
	std::cout << '|' << format_text(nbr) \
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

int		Contact::get_contact_id(void)
{
	return(id);
}

void	Contact::update_contact_id(int new_id)
{
	id = new_id;
}