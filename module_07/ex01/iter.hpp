/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:22:03 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/14 20:47:45 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cctype>

template <typename T, typename F>
void iter(T* arr, int len, F func)
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

#endif