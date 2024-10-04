/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:02:43 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 17:09:04 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (!isSigned())
		throw RobotomyRequestForm::FormIsUnsigned();
	else if (b.getGrade() > getExecGrade())
	{
		std::cout << target << ": robotomy failed" << std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
	else if (b.getGrade() <= getExecGrade())
	{
		std::cout << "MAKING NOISES!!!!" << std::endl;
		std::cout << target << " has been robotomized successfully 50\% of the time" << std::endl;
	}
}

Form* RobotomyRequestForm::makeForm(Form *form, std::string form_name, std::string target_name)
{
	if (form == NULL && form_name == "robotomy request")
		return (new RobotomyRequestForm(target_name));
	return (form);
}