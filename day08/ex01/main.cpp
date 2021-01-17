/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:13:14 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/17 10:44:04 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

bool test_simple_addNumber(void)
{
	Span sp(3);
	sp.addNumber(0);
	sp.addNumber(1);
	sp.addNumber(2);

	bool result = sp.longestSpan() == 2 && sp.shortestSpan() == 1;

	try
	{
		sp.addNumber(3);
		result = false;
	}
	catch (Span::ContainerFullException const &e)
	{
		std::cout << e.what() << std::endl;
		result = result && true;
	}
	return result;
}

bool test_addNumber_from_vector(void)
{
	int arr[] = {2, 0, 1};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	Span sp(3);
	sp.addNumber(sp.end(), vec.begin(), vec.end());

	bool result = sp.longestSpan() == 2 && sp.shortestSpan() == 1;

	try
	{
		sp.addNumber(3);
		result = false;
	}
	catch (Span::ContainerFullException const &e)
	{
		std::cout << e.what() << std::endl;
		result = result && true;
	}
	return result;
}

bool test_addNumber_from_array(void)
{
	int arr[] = {2, 0, 1};

	Span sp(3);
	sp.addNumber(sp.end(), arr, arr + sizeof(arr) / sizeof(int));

	bool result = sp.longestSpan() == 2 && sp.shortestSpan() == 1;

	try
	{
		sp.addNumber(3);
		result = false;
	}
	catch (Span::ContainerFullException const &e)
	{
		std::cout << e.what() << std::endl;
		result = result && true;
	}
	return result;
}

bool test_addNumber_from_span(void)
{
	int arr1[] = {2, 0, 1};
	int arr2[] = {3, 5, 4};

	Span sp1(6);
	sp1.addNumber(sp1.end(), arr1, arr1 + sizeof(arr1) / sizeof(int));

	Span sp2(3);
	sp2.addNumber(sp2.end(), arr2, arr2 + sizeof(arr2) / sizeof(int));

	sp1.addNumber(sp1.end(), sp2.begin(), sp2.end());

	bool result = sp1.longestSpan() == 5 && sp1.shortestSpan() == 1;

	try
	{
		sp1.addNumber(3);
		result = false;
	}
	catch (Span::ContainerFullException const &e)
	{
		std::cout << e.what() << std::endl;
		result = result && true;
	}
	return result;
}

int main(void)
{
	// Test simple addNumber
	show_result("Test simple addNumber", test_simple_addNumber());

	// Test addNumber from vector
	show_result("Test addNumber from vector", test_addNumber_from_vector());

	// Test addNumber from array
	show_result("Test addNumber from array", test_addNumber_from_array());

	// Test addNumber from span
	show_result("Test addNumber from span", test_addNumber_from_span());
	return 0;
}
