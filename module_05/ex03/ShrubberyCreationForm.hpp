/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:36:08 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 21:07:43 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORN_HPP
#define SHRUBBERYCREATIONFORN_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string	target;

	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
public:
	virtual ~ShrubberyCreationForm(){};
	ShrubberyCreationForm(std::string target);
	void	execute(Bureaucrat const &b) const;

	static Form* makeForm(Form *form, std::string form_name, std::string target_name);
};

#endif