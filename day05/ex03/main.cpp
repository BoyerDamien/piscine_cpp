/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:09:08 by root              #+#    #+#             */
/*   Updated: 2021/01/15 11:30:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

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
bool test_intern_methods(void)
{
	Intern intern;

	AForm *p = intern.makeAForm("Presidential pardon", "test");
	AForm *s = intern.makeAForm("Shrubbery creation", "test");
	AForm *r = intern.makeAForm("Robotomy request", "test");
	AForm *n = intern.makeAForm("null", "test");

	std::cout << *p << std::endl;
	std::cout << *s << std::endl;
	std::cout << *r << std::endl;
	std::cout << n << std::endl;

	delete p;
	delete s;
	delete r;
	delete n;
	return true;
}
int main(void)
{
	// Test forms methods
	show_result("Test forms methods", test_intern_methods());
	return 0;
}
