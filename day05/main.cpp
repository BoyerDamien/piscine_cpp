/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:09:08 by root              #+#    #+#             */
/*   Updated: 2021/01/12 15:08:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <exception>

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

bool test_attributes()
{
	Bureaucrat b("test", 10);

	return b.getGrade() == 10 && b.getName() == "test";
}

bool test_assignations()
{
	Bureaucrat b1("test", 10);
	Bureaucrat b2(b1);
	Bureaucrat b3 = b2;

	return b1 == b2 && b2 == b3;
}

bool test_exceptions()
{
	bool result = false;
	try
	{
		Bureaucrat b("test", 0);
	}
	catch (std::exception &e)
	{
		result = true;
	}
	try
	{
		Bureaucrat b("test", 151);
		result = false;
	}
	catch (std::exception &e)
	{
		result = result && true;
	}
	try
	{
		Bureaucrat b("yrdy", 10);
		result = result && true;
	}
	catch (std::exception &e)
	{
		result = false;
	}
	return result;
}

bool test_methods()
{
	Bureaucrat b("test", 1);
	b.decrement();

	bool result = b.getGrade() == 2;

	b.intcrement();
	b.intcrement();

	result = result && b.getGrade() == 1;

	Bureaucrat b2("test2", 150);
	b2.decrement();

	return result && b2.getGrade() == 150;
}

int main()
{
	// Test attributes
	show_result("Test attributes", test_attributes());

	// Test assignations
	show_result("Test assignations", test_assignations());

	// Test exceptions
	show_result("Test exceptions", test_exceptions());

	// Test methods
	show_result("Test methods", test_methods());
	return 0;
}
