/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:33:17 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/04 15:56:04 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	if (!isSigned())
		throw ShrubberyCreationForm::FormIsUnsigned();
	else if (b.getGrade() > getExecGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (b.getGrade() <= getExecGrade())
	{
			std::ofstream	ofs((target + "_shrubbery").c_str());
		if (!ofs.is_open())
		{
			std::cerr << "Error while creating the outfile" << std::endl;
			return ;
		}
		ofs << "   *    *  ()   *   *" << std::endl;
		ofs << "*        * /         *" << std::endl;
		ofs << "      *   /i\\    *  *" << std::endl;
		ofs << "    *     o/\\  *      *" << std::endl;
		ofs << " *       ///    *" << std::endl;
		ofs << "     *   /*/o\\  *    *" << std::endl;
		ofs << "   *    /i//      *" << std::endl;
		ofs << "        /o/*\\i   *" << std::endl;
		ofs << "  *    //i//o\\\\     *" << std::endl;
		ofs << "    * /*////\\\\i" << std::endl;
		ofs << " *    //o//i\\*\\   *" << std::endl;
		ofs << "   * /i///*/\\\\   *" << std::endl;
		ofs << "  *    *   ||     *" << std::endl;
		ofs.close();
		std::cout << "File " << target << "_shrubbery is created with ASCII tree inside" << std::endl;
	}
}