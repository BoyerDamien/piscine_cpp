/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 12:10:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ScavTrap.hpp"
#include <iostream>

const std::string SEPARATOR =
	"\n\n################################################"
	"##########################################\n\n";

void show_result(std::string message, bool status)
{

	std::cerr << SEPARATOR << std::endl;
	if (status)
	{
		std::cerr << message << "[OK]" << std::endl;
	}
	else
	{
		std::cerr << message << "[KO]" << std::endl;
	}
	std::cerr << SEPARATOR << std::endl;
}

bool test_attributes(int attributesCorrectValues[], int attributesRealValues[])
{
	for (int i = 0; i < 8; i++)
	{
		if (attributesRealValues[i] != attributesCorrectValues[i])
		{
			std::cerr << "I = " << i << " " << attributesCorrectValues[i]
					  << " != " << attributesRealValues[i] << std::endl;
			return false;
		}
	}
	return true;
}

bool test_attributesScav(ScavTrap &defaultscav, std::string name)
{
	int attributesCorrectValues[] = {100, 100, 50, 50, 1, 20, 15, 3};
	int attributesRealValues[] = {
		defaultscav.getHP(),		   defaultscav.getMaxHP(),
		defaultscav.getEnergyPoint(),  defaultscav.getMaxEnergyPoint(),
		defaultscav.getLevel(),		   defaultscav.getMeleeAttack(),
		defaultscav.getRangedAttack(), defaultscav.getArmorDamageReduction()};

	// Test Name
	if (name != defaultscav.getName())
	{
		std::cerr << defaultscav.getName() << " != " << name << std::endl;

		return false;
	}

	return test_attributes(attributesCorrectValues, attributesRealValues);
}

bool test_assignation(void)
{
	// Test copy and assignation for ScavTrap
	ScavTrap scav = ScavTrap("scav");
	ScavTrap copyScav = ScavTrap(scav);
	ScavTrap assignationScav = scav;

	bool result1 = (copyScav == scav) && (scav == assignationScav) &&
				   (copyScav == assignationScav);
	show_result("ScavTrap assignation test: ", result1);

	test_attributesScav(scav, "scav");
	test_attributesScav(copyScav, "scav");
	test_attributesScav(assignationScav, "scav");

	return result1;
}

bool test_constructors(void)
{
	std::cout << std::endl << "TEST CONSTRUCTORS" << std::endl << std::endl;

	// ScavTrap testing
	ScavTrap defaultscav = ScavTrap();
	ScavTrap damien = ScavTrap("Damien");

	bool result = test_attributesScav(defaultscav, "Default");
	show_result("ScavTrap est attributes default: ", result);

	result = test_attributesScav(damien, "Damien");
	show_result("ScavTrap test attributes normal constructor: ", result);

	return result;
}

void test_methods(void)
{
	std::cout << SEPARATOR << std::endl;
	std::cout << "ScavTrap methods test" << std::endl;
	std::cout << SEPARATOR << std::endl;

	ScavTrap scav = ScavTrap("Scav");
	scav.challengeNewcomer();
	scav.meleeAttack("target");
	scav.rangedAttack("target");
	scav.takeDamage(20);
	scav.beRepaired(20);
}

int main(void)
{
	if (test_constructors() && test_assignation())
	{
		test_methods();
		return 0;
	}
	return 1;
}
