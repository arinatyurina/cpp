/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:07:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/30 13:15:49 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	std::string const	name;
	int	grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	std::string const	&getName() const;
	int	getGrade() const;
	
	void	incrementGrade();
	void	decrementGrade();

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

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);