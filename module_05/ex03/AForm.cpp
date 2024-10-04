/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:43:26 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 20:12:10 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

Form::Form() : name("unknown"), is_signed(false), sign_grade(150), exec_grade(150)
{
	std::cout << "[Form] Default constructor called" << std::endl;
}

Form::Form(std::string myName, int s_grade, int e_grade): name(myName), is_signed(false), sign_grade(s_grade), exec_grade(e_grade)
{
	if (s_grade > 150 || e_grade > 150)
		throw Form::GradeTooHighException();
	else if (s_grade < 1 || e_grade < 1)
		throw Form::GradeTooLowException();
	std::cout << "[Form] " << myName << " constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "[Form] " << getName() << " destructor called" << std::endl;
}

Form::Form(const Form& other) : name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade) 
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

std::string const	&Form::getName() const
{
	return (name);
}

int	Form::getExecGrade() const
{
	return (exec_grade);
}

int	Form::getSignGrade() const
{
	return (sign_grade);
}

bool	Form::isSigned() const
{
	return(is_signed);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getSignGrade())
		this->is_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& stream, const Form& b)
{
	stream << b.getName() << " form: grade to sign - " << b.getSignGrade() << ", grade to execute - " << b.getExecGrade() << std::endl;
	return (stream);
}

Form* Form::makeForm(std::string form_name, std::string target_name)
{
	Form* form = 0;
	form = ShrubberyCreationForm::makeForm(form, form_name, target_name);
	form = RobotomyRequestForm::makeForm(form, form_name, target_name);
	form = PresidentalPardonForm::makeForm(form, form_name, target_name);
	return (form);
}