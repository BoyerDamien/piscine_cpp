/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/31 09:39:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./NinjaTrap.hpp"
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

bool test_attributesNinja(NinjaTrap defaultninja, std::string name)
{
	int attributesCorrectValues[] = {60, 60, 120, 120, 1, 60, 5, 0};
	int attributesRealValues[] = {
		defaultninja.getHP(),			defaultninja.getMaxHP(),
		defaultninja.getEnergyPoint(),	defaultninja.getMaxEnergyPoint(),
		defaultninja.getLevel(),		defaultninja.getMeleeAttack(),
		defaultninja.getRangedAttack(), defaultninja.getArmorDamageReduction()};

	// Test Name
	if (name != defaultninja.getName())
	{
		std::cerr << defaultninja.getName() << " != " << name << std::endl;

		return false;
	}

	return test_attributes(attributesCorrectValues, attributesRealValues);
}

bool test_assignation(void)
{
	// Test copy and assignation for NinjaTrap
	NinjaTrap ninja = NinjaTrap("ninja");
	NinjaTrap copyNinja = NinjaTrap(ninja);
	NinjaTrap assignationNinja = ninja;

	bool result1 = (copyNinja == ninja) && (ninja == assignationNinja) &&
				   (copyNinja == assignationNinja);
	show_result("NinjaTrap assignation test: ", result1);

	return result1;
}

bool test_constructors(void)
{
	std::cout << std::endl << "TEST CONSTRUCTORS" << std::endl << std::endl;

	// NinjaTrap testing
	NinjaTrap defaultninja = NinjaTrap();
	NinjaTrap damien = NinjaTrap("Damien");

	bool result = test_attributesNinja(defaultninja, "Default");
	show_result("NinjaTrap test attributes default: ", result);

	result = test_attributesNinja(damien, "Damien");
	show_result("NinjaTrap test attributes normal constructor: ", result);

	return result;
}

void test_methods(void)
{

	std::cout << SEPARATOR << std::endl;
	std::cout << "NinjaTrap methods test" << std::endl;
	std::cout << SEPARATOR << std::endl;

	NinjaTrap ninja = NinjaTrap("Ninja");
	FragTrap frag = FragTrap("frag");
	ScavTrap scav = ScavTrap("scav");

	ninja.ninjaShoeBox(ninja);
	ninja.ninjaShoeBox(scav);
	ninja.ninjaShoeBox(frag);
	ninja.meleeAttack("target");
	ninja.rangedAttack("target");
	ninja.takeDamage(20);
	ninja.beRepaired(20);
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
