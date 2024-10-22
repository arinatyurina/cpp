/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:05:01 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/22 15:57:29 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

/*MutantStack, which is a special type of stack that 
allows you to use iterators to go through its elements*/

/*Defining a template for a class, which is a way to create 
a class that can work with any data type (like integers, floats, or even custom objects).
T: This is a placeholder for the type of items that stack will hold.
Container: This is the type of data structure used to store the items. 
By default, it uses std::deque<T>, which is a flexible way to store data.*/

template < class T, class Container = std::deque<T> > //the default container type for the std::stack class is std::deque<T>
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;

	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack& operator=(const MutantStack &other);

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

template <class T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &other)
{
	if (this != *other)
		std::stack<T, Container>::operator=(other); // calling the assignment operator from the base class
	return (*this);
}

#endif