/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:46:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"
#include "./SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

const std::string SEPARATOR =
	"\n\n################################################"
	"##########################################\n\n";

/******************************************************************************
 *														TEST FUNCTIONS
 ******************************************************************************/

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

bool test_attributesSuper(SuperTrap &defaultsuper, std::string name)
{
	int attributesCorrectValues[] = {100, 100, 120, 120, 1, 60, 20, 5};
	int attributesRealValues[] = {
		defaultsuper.getHP(),			defaultsuper.getMaxHP(),
		defaultsuper.getEnergyPoint(),	defaultsuper.getMaxEnergyPoint(),
		defaultsuper.getLevel(),		defaultsuper.getMeleeAttack(),
		defaultsuper.getRangedAttack(), defaultsuper.getArmorDamageReduction()};

	for (int i = 0; i < 8; i++)
	{
		std::cout << "Attr = " << i << " " << attributesRealValues[i]
				  << std::endl;
	}
	// Test Name
	if (name != defaultsuper.getName())
	{
		std::cerr << defaultsuper.getName() << " != " << name << std::endl;

		return false;
	}

	return test_attributes(attributesCorrectValues, attributesRealValues);
}

bool test_assignation(void)
{
	// Test copy and assignation for SuperTrap
	SuperTrap super = SuperTrap("super");
	SuperTrap copySuper = SuperTrap(super);
	SuperTrap assignationSuper = super;

	test_attributesSuper(super, "super");
	test_attributesSuper(copySuper, "super");
	test_attributesSuper(assignationSuper, "super");
	bool result1 = (copySuper == super) && (super == assignationSuper) &&
				   (copySuper == assignationSuper);
	show_result("SuperTrap assignation test: ", result1);

	return result1;
}

bool test_constructors(void)
{
	std::cout << std::endl << "TEST CONSTRUCTORS" << std::endl << std::endl;

	// SuperTrap testing
	SuperTrap defaultsuper = SuperTrap();
	SuperTrap damien = SuperTrap("Damien");

	bool result1 = test_attributesSuper(defaultsuper, "Default");
	show_result("SuperTrap test attributes default: ", result1);

	bool result2 = test_attributesSuper(damien, "Damien");
	show_result("SuperTrap test attributes normal constructor: ", result2);

	return result1 && result2;
}

void test_methods(void)
{

	std::cout << SEPARATOR << std::endl;
	std::cout << "SuperTrap methods test" << std::endl;
	std::cout << SEPARATOR << std::endl;

	SuperTrap super = SuperTrap("Super");
	FragTrap frag = FragTrap("frag");
	ScavTrap scav = ScavTrap("scav");
	NinjaTrap ninja = NinjaTrap("ninja");

	// common attacks
	super.meleeAttack("target");
	super.rangedAttack("target");

	// specific attacks
	super.ninjaShoeBox(frag);
	super.ninjaShoeBox(scav);
	super.ninjaShoeBox(ninja);
	super.vaulthunter_dot_exe("target");
}

/******************************************************************************
 *																	MAIN
 ******************************************************************************/
int main(void)
{
	if (test_constructors() && test_assignation())
	{
		test_methods();
		return 0;
	}
	return 1;
}
