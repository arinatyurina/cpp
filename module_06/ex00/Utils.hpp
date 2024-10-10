/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:31:01 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/10 23:34:29 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "ScalarConverter.hpp"

bool	isDouble(std::string s);
bool	isFloat(std::string s);
bool	isInt(std::string s);
bool isSpecialLiteral(std::string s);
void	handleSpecialLiteral(std::string s);
bool isNumberInRange(const std::string &s, long min, long max);

#endif