/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:01:05 by atyurina          #+#    #+#             */
/*   Updated: 2026/01/24 18:23:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void	list_iter()
{
	std::cout << ">>>>>Creating and iterating std::list<<<<<" << std::endl;
	std::list<int>	list;
	list.push_back(5);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void test_string()
{
	std::cout << ">>>>>Creating stack of strings with MutantStack:<<<<<" << std::endl;
	MutantStack<std::string> string_stack;

	string_stack.push("wishing");
	string_stack.push("you");
	string_stack.push("happiness");
	string_stack.push("^-^");
	
	MutantStack<std::string>::iterator it = string_stack.begin();
	MutantStack<std::string>::iterator ite = string_stack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	std::cout << ">>>>>Running basic MutantStack test<<<<<" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	/*I copy my MutantStack into a std::stack to prove
	that MutantStack remains fully compatible with the standard stack interface 
	and that my added iterators do not break its behavior.
	
	Since it is LIFO — Last In, First Out, he values are printed in reverse order...*/
	std::cout << "Contents of the copied original std::stack:" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl; // Print the top element of `s`
		s.pop(); // Remove the top element from `s`
	}

	test_string();
	list_iter();
	return 0;
}