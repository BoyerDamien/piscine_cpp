/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:57:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./FragTrap.hpp"
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

bool test_attributesFrag(FragTrap &defaultfrag, std::string name)
{
	int attributesCorrectValues[] = {100, 100, 100, 100, 1, 30, 20, 5};
	int attributesRealValues[] = {
		defaultfrag.getHP(),		   defaultfrag.getMaxHP(),
		defaultfrag.getEnergyPoint(),  defaultfrag.getMaxEnergyPoint(),
		defaultfrag.getLevel(),		   defaultfrag.getMeleeAttack(),
		defaultfrag.getRangedAttack(), defaultfrag.getArmorDamageReduction()};

	// Test Name
	if (name != defaultfrag.getName())
	{
		std::cerr << defaultfrag.getName() << " != " << name << std::endl;

		return false;
	}

	return test_attributes(attributesCorrectValues, attributesRealValues);
}

bool test_assignation(void)
{
	// Test copy and assignation for FragTrap
	FragTrap frag = FragTrap("frag");
	FragTrap copyFrag = FragTrap(frag);
	FragTrap assignationFrag = frag;

	bool result1 = (copyFrag == frag) && (frag == assignationFrag) &&
				   (copyFrag == assignationFrag);
	show_result("FragTrap assignation test: ", result1);

	return result1;
}

bool test_constructors(void)
{
	std::cout << std::endl << "TEST CONSTRUCTORS" << std::endl << std::endl;

	// FragTrap testing
	FragTrap defaultfrag = FragTrap();
	FragTrap damien = FragTrap("Damien");

	bool result = test_attributesFrag(defaultfrag, "Default");
	show_result("FragTrap est attributes default: ", result);

	result = test_attributesFrag(damien, "Damien");
	show_result("FragTrap test attributes normal constructor: ", result);

	return result;
}

void test_methods(void)
{

	std::cout << SEPARATOR << std::endl;
	std::cout << "FragTrap methods test" << std::endl;
	std::cout << SEPARATOR << std::endl;

	FragTrap frag = FragTrap("Frag");
	frag.vaulthunter_dot_exe("target");
	frag.meleeAttack("target");
	frag.rangedAttack("target");
	frag.takeDamage(20);
	frag.beRepaired(20);
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
