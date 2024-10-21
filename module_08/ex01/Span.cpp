/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/21 16:55:17 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : N(n) {}

	
Span::Span(const Span &other) : N(other.N), arr(other.arr) {}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		arr = other.arr;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (arr.size() < N)
		arr.push_back(n);
	else
		throw std::runtime_error("Span is already full. You can not add any more elements.");
}

void	Span::addNumber(std::vector<int> vec)
{
	if (arr.size() + vec.size() < N)
		arr.insert(arr.end(), vec.begin(), vec.end());
	else
		throw std::runtime_error("Span can not add that many numbers. There is no enought space.");
}

int	Span::shortestSpan() const
{
	if (arr.size() > 1)
	{
		int ret = abs(arr[0] - arr[1]);
		std::vector<int> tmp(arr);
		std::sort(tmp.begin(), tmp.end());
		for (unsigned long i = 1; i + 1 < tmp.size(); i++)
		{
			if (tmp[i + 1] - tmp[i] < ret)
				ret = tmp[i + 1] - tmp[i];
		}
		return (ret);
	}
	else
		throw std::runtime_error("There are less than 2 elements. Impossible to get shortest span.");
}

int	Span::longestSpan() const
{
	if (arr.size() > 1)
	{
		std::vector<int>::const_iterator itMax = std::max_element(arr.begin(), arr.end());
		std::vector<int>::const_iterator itMin = std::min_element(arr.begin(), arr.end());
		int	nMax = *itMax;
		int	nMin = *itMin;
		return (nMax - nMin);
	}
	else
		throw std::invalid_argument("There are less than 2 elements. Impossible to get longest span.");
}
