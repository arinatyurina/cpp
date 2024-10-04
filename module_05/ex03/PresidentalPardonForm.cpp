/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:13:23 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 17:09:34 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"
#include <fstream>

PresidentalPardonForm::PresidentalPardonForm(std::string target) : Form("PresidentalPardonForm", 25, 5), target(target) {}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm& other)
{
	*this = other;
}

PresidentalPardonForm& PresidentalPardonForm::operator=(const PresidentalPardonForm& other)
{
	if (this != &other) {}
	return *this;
}

void	PresidentalPardonForm::execute(Bureaucrat const &b) const
{
	if (!isSigned())
		throw PresidentalPardonForm::FormIsUnsigned();
	else if (b.getGrade() > getExecGrade())
	{
		throw PresidentalPardonForm::GradeTooLowException();
	}
	else if (b.getGrade() <= getExecGrade())
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

Form* PresidentalPardonForm::makeForm(Form *form, std::string form_name, std::string target_name)
{
	if (form == NULL && form_name == "presidental pardon")
		return (new PresidentalPardonForm(target_name));
	return (form);
}