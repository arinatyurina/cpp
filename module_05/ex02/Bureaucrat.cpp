/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:39 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/30 14:51:06 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150)
{
	std::cout << "[Bureaucrat] Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string myName, int grade): name(myName)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "[Bureaucrat] " << myName << " constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] " << getName() << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
	return (stream);
}


void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed form " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign form  " << f.getName() << " because ->"<<std::endl;
		std::cerr << "Exception: " << e.what() << '\n';
	}
}
