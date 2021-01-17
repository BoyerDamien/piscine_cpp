/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:36:39 by root              #+#    #+#             */
/*   Updated: 2021/01/17 13:22:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mutantstack.hpp"

const std::string SEPARATOR =
	"\n\n################################################"
	"##########################################\n\n";

void show_result(std::string message, bool status)
{

	std::cerr << SEPARATOR << std::endl;
	if (status)
	{
		std::cerr << message << ": [OK]" << std::endl;
	}
	else
	{
		std::cerr << message << ": [KO]" << std::endl;
	}
	std::cerr << SEPARATOR << std::endl;
}

bool test_stack_add(void)
{
	MutantStack<int> st;

	for (int i = 0; i < 10; i++)
	{
		st.push(i);
	}
	bool result = st.size() == 10 && st.top() == 9;

	MutantStack<int>::iterator it = st.begin();
	for (int i = 0; i < 10; i++)
	{
		result = result && *it == i;
		it++;
	}
	return result;
}

bool test_stack_iterator(void)
{
	MutantStack<int> st;

	for (int i = 0; i < 10; i++)
	{
		st.push(i);
	}
	bool result = true;
	MutantStack<int>::iterator it = st.begin();
	for (int i = 0; i < 10; i++)
	{
		result = result && *it == i;
		it++;
	}
	return result;
}

int main(void)
{
	// Test stack add
	show_result("Test stack add", test_stack_add());

	// Test stack iterator
	show_result("Test stack iterator", test_stack_iterator());
}
