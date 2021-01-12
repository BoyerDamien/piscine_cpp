/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:09:08 by root              #+#    #+#             */
/*   Updated: 2021/01/12 16:28:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

bool test_form_attributes()
{
	Form f("test", 1, 1);

	return f.getName() == "test" && f.getGradeToExec() == 1 &&
		   f.getGradeToSign() == 1;
}

bool test_form_assignations()
{
	Form f1("test", 1, 1);
	Form f2(f1);
	Form f3 = f2;

	return f1 == f2 && f2 == f3;
}

bool test_form_methods()
{
	Form f("f", 10, 150);
	Form f2("f", 10, 150);

	Bureaucrat b1("b", 9);
	Bureaucrat b2("b", 11);

	b1.signForm(f);

	bool result = f.isSigned();
	b2.signForm(f2);

	return result && !f2.isSigned();
}

bool test_exceptions()
{
	bool result = false;
	try
	{
		Form f("f", -1, 1);
	}
	catch (std::exception &e)
	{
		result = true;
	}
	try
	{
		Form f("f", 1, -1);
		result = false;
	}
	catch (std::exception &e)
	{
		result = result && true;
	}
	try
	{
		Form f("f", 151, 1);
		result = false;
	}
	catch (std::exception &e)
	{
		result = result && true;
	}
	try
	{
		Form f("f", 1, 151);
		result = false;
	}
	catch (std::exception &e)
	{
		result = result && true;
	}
	return result;
}

int main(void)
{
	// Test form attributes
	show_result("Test form attributes", test_form_attributes());

	// Test form assignations
	show_result("Test form assignations", test_form_assignations());

	// Test form methods
	show_result("Test form methods", test_form_methods());

	// Test form exceptions
	show_result("Test for exceptions", test_exceptions());
	return 0;
}
