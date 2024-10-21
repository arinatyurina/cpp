/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/21 16:25:52 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int	N;
	std::vector<int>	arr;
public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span &other);
	Span& operator=(const Span &other);

	void	addNumber(int n);
	void	addNumber(std::vector<int> vec);
	int	shortestSpan() const;
	int	longestSpan() const;
};

#endif