/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:57:54 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/05 16:57:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
visibility:
private members of a class are accessible only from within other members of the same class (or from their "friends").
protected members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
Finally, public members are accessible from anywhere where the object is visible.
*/

#ifndef HEADER_H
# define HEADER_H

#include <iostream>
#include <string>
#include <limits>
//class, attributes and functions it contains
/*classes allow us to group variables together into a type
and also add functionality to those variables*/

class Contact
{
private:
	std::string	First_name;
	std::string	Last_name;
	std::string	Nickname;
	std::string	Phone_number;
	std::string	Darkest_secret;

public:
//	Contact();
//	~Contact();
	int		id;
	void	set_first_name(const std::string&);
	void	set_last_name(const std::string&);
	void	set_nickname(const std::string&);
	void	set_phone_number(const std::string&);
	void	set_darkest_secret(const std::string&);
	void	print_contact(void);
	void	print_contact_column(void);
};

// Contact::Contact() : First_name(""), Last_name(""), Nickname(""), Phone_number(""), Darkest_secret("")
// {

// }

// Contact::~Contact()
// {

// }

class PhoneBook
{
private:
	Contact	Contacts[8];
	int		Next;
	int		Amount;
public:
	PhoneBook()
	{
		Next = 0;
		Amount = 0;
	}
//	~PhoneBook();
	
	void	add(const Contact& contact);
	void	search(void);
	int		getAmount(void);
	int		getNext(void);
	void	updateContactId(void);
	int 	ContactIndexById(int id);
	const Contact& getContact(int index) const;
};

//constructors and destructors do not return anything
// PhoneBook::PhoneBook()
// {
// 	Next = 0;
// 	Amount = 0;
// }

// PhoneBook::~PhoneBook()
// {

// }

std::string format_text(const std::string &text);

#endif