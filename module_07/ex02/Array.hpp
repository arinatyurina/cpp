/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:01:37 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/15 00:38:11 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T	*elements;
	unsigned int	num;
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array& other);
	Array<T>& operator=(const Array& other);
	
	T& operator[](unsigned int index);

	int	size(void) const;
};

template <typename T>
Array<T>::Array() : num(0), elements(NULL)
{

}

template <typename T>
Array<T>::Array(unsigned int n) : num(n)
{
	elements = new T[num];
}

template <typename T>
Array<T>::~Array()
{
	delete [] elements;
}

template <typename T>
Array<T>::Array(const Array& other) : num(other->num), elements(new T[num])
{
	for (int i = 0; i < num; i++)
		elements[i] = other->elements[i];
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= num)
		throw std::out_of_range("Index is out of bound");
	else
		return (elements[idx]);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != other)
	{
		num = other->num;
		elements = new T[num];
		for (int i = 0; i < num; i++)
			elements[i] = other->elements[i];
	}
	return (this);
}

template <typename T>
int	Array<T>::size(void) const
{
	return (num);
}

#endif