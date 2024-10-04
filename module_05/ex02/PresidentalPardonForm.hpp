/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:57:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 15:54:48 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentalPardonForm : public Form
{
private:
	std::string	target;

	PresidentalPardonForm(const PresidentalPardonForm& other);
	PresidentalPardonForm& operator=(const PresidentalPardonForm& other);
public:
	virtual ~PresidentalPardonForm(){};
	PresidentalPardonForm(std::string target);
	void	execute(Bureaucrat const &b) const;
};

#endif