/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:46:13 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/27 22:38:40 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <iostream>
# include<fstream> //file stream operations

int	out_file(std::ifstream &ifs, std:: string filename, std::string s1, std::string s2);
std::string modify_text(std::ifstream& ifs, const std::string& s1, const std::string& s2);

#endif