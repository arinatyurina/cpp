/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:12:18 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 20:39:36 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& other)
{
	*this = other;
}

	Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

Form*	Intern::makeForm(std::string form, std::string target)
{
	Form	*f;

	f = Form::makeForm(form, target);
	if (!f)
		std::cout << "Form " << form << " can not be found" << std::endl;
	else
		std::cout << "Intern creates " << form << std::endl;
	return (f);
}


/**However, the intern has one important capacity: the makeForm() function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.
It will print something like:
Intern creates <form>
If the form name passed as parameter doesn’t exist, print an explicit error messag*/