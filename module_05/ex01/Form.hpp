/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:31:26 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/30 14:54:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool	is_signed;
	const int	sign_grade;
	const int	exec_grade;

	Form(const Form& other);
	Form& operator=(const Form& other);

public:
	Form();
	Form(std::string name, int s_grade, int e_grade);
	~Form();

	std::string const	&getName() const;
	int	getSignGrade() const;
	int	getExecGrade() const;
	bool	isSigned() const;
	void	beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Grade is too High");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Grade is too Low");
		}
	};
};

std::ostream& operator<<(std::ostream& stream, const Form& b);

#endif 