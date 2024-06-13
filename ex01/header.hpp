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
//class, attributes and functions it contains
/*classes allow us to group variables together into a type
and also add functionality to those variables*/

class Contact
{
private:
	int			id;
	std::string	first_name;
	std::string	first_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact(/* args */);
	~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

class PhoneBoook
{
private:
	/* data */
	Contact	contact[8];
	int		id;
	int		amount;
public:
	PhoneBoook(/* args */);
	~PhoneBoook();
	
	void	add(Contact Contact);
	void	search(PhoneBoook PhoneBoook);
	void	exit(void);
};

//cpnstructors and destructors do not returt anything
PhoneBoook::PhoneBoook(/* args */)
{
}

PhoneBoook::~PhoneBoook()
{
}

#endif