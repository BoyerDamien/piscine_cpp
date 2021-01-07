/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:49:29 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 15:35:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Peon.hpp"
#include "./Sorcerer.hpp"
#include "Victim.hpp"
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

bool test_sorcerer_attributes(std::string const &name, std::string const &title)
{
	Sorcerer sorcerer = Sorcerer(name, title);

	bool result1 = sorcerer.getName() == name;
	if (!result1)
	{
		std::cerr << sorcerer.getName() << " != " << name << std::endl;
	}
	bool result2 = sorcerer.getTitle() == title;
	if (!result2)
	{
		std::cerr << sorcerer.getTitle() << " != " << title << std::endl;
	}

	return result1 && result1;
}

bool test_sorcerer_assignations(void)
{
	Sorcerer sorcerer1("Robert", "The magnificent");
	Sorcerer sorcerer2(sorcerer1);
	Sorcerer sorcerer3 = sorcerer2;

	return sorcerer1 == sorcerer2 && sorcerer3 == sorcerer1;
}

bool test_sorcerer_methods(void)
{
	Sorcerer sorcerer = Sorcerer("Robert", "The magnificent");
	Peon peon("peon");
	Victim victim("victim");

	sorcerer.polymorph(peon);
	sorcerer.polymorph(victim);

	std::cout << sorcerer << std::endl;
	return true;
}

bool test_peon_assignation(void)
{
	Peon peon1("peon");
	Peon peon2(peon1);
	Peon peon3 = peon2;

	return peon1 == peon2 && peon2 == peon3;
}

bool test_peon_methods(void)
{
	Peon peon1("peon");

	std::cout << peon1 << std::endl;
	return true;
}

int main(void)
{
	// Test attributes
	show_result("Test sorcerer attributes and getters",
				test_sorcerer_attributes("Robert", "The magnificent"));

	// Test assignation
	show_result("Test sorcerer assignation", test_sorcerer_assignations());

	// Test peon assignation
	show_result("Test peon assignation", test_peon_assignation());

	// Test sorcerer methods;
	show_result("Test sorcerer methods", test_sorcerer_methods());

	// Test Peon methods;
	show_result("Test peon methods", test_peon_methods());
	return 0;
}
