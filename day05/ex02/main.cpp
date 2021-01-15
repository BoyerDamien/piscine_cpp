/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:09:08 by root              #+#    #+#             */
/*   Updated: 2021/01/15 09:01:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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

bool test_one_attribute(AForm const &f, std::string const &name,
						std::string const &target, int const sign,
						int const exec)
{
	return f.getName() == name && f.getGradeToSign() == sign &&
		   f.getGradeToExec() == exec && f.getTarget() == target;
}

bool test_form_attributes(void)
{
	ShrubberyCreationForm sh("sh");
	RobotomyRequestForm rb("rb");
	PresidentialPardonForm pr("pr");

	return test_one_attribute(sh, "Shrubbery", "sh", 145, 137) &&
		   test_one_attribute(rb, "Robotomy", "rb", 72, 45) &&
		   test_one_attribute(pr, "Pardon", "pr", 25, 5);
}

bool test_forms_assignation(void)
{
	ShrubberyCreationForm sh1("sh1");
	ShrubberyCreationForm sh2(sh1);
	ShrubberyCreationForm sh3 = sh2;

	bool result = sh1 == sh2 && sh2 == sh3;

	RobotomyRequestForm rb1("rb1");
	RobotomyRequestForm rb2(rb1);
	RobotomyRequestForm rb3 = rb2;

	result = result && rb1 == rb2 && rb2 == rb3;

	PresidentialPardonForm p1("p1");
	PresidentialPardonForm p2(p1);
	PresidentialPardonForm p3 = p2;

	return result && p1 == p2 && p2 == p3;
}

bool test_forms_methods(void)
{
	ShrubberyCreationForm sh("sh");
	PresidentialPardonForm p("p");
	RobotomyRequestForm rb("rb");
	Bureaucrat b1("b1", 1);

	// Test exec non signed forms
	b1.executeAForm(sh);
	b1.executeAForm(p);
	b1.executeAForm(rb);

	// Test exec signed forms
	b1.signAForm(sh);
	b1.signAForm(p);
	b1.signAForm(rb);

	b1.executeAForm(sh);
	b1.executeAForm(p);
	b1.executeAForm(rb);

	Bureaucrat b2("b2", 150);

	b2.executeAForm(sh);
	b2.executeAForm(p);
	b2.executeAForm(rb);

	return true;
}

int main(void)
{
	// Test forms attributes
	show_result("Test forms attributes", test_form_attributes());

	// Test forms assignations
	show_result("Test forms assignations", test_forms_assignation());

	// Test forms methods
	show_result("Test forms methods", test_forms_methods());
}
