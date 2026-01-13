/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:22:03 by atyurina          #+#    #+#             */
/*   Updated: 2026/01/12 21:49:13 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cctype>

template <typename T>
void iter(T* arr, size_t len, void (*func)(T&))
{
//	std::cout << "Template with non-const reference to function was called:\n";
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void iter(T* arr, size_t len, void (*func)(const T&))
{
//	std::cout << "Template with const reference to function was called:\n";
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}


#endif