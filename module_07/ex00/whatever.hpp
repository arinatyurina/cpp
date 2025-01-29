/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:53:15 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/29 17:11:59 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// The template <typename T> allows it to work with any data type 
// (int, float, double, std::string, etc.).

// Ternaty operator (?:)
//condition ? expression_if_true : expression_if_false;

template <typename T>
T const & max(T const &a, T const &b)
{
	return (a >= b ? a : b);
}

template <typename T>
T const & min(T const &a, T const &b)
{
	return (a <= b ? a : b);
}

template <typename T>
void	swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif