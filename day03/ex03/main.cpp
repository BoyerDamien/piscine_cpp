/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 19:32:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./NinjaTrap.hpp"
#include "./ScavTrap.hpp"
#include <iostream>
#include <string>

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
		std::cerr << message << "KO" << std::endl;
	}
	std::cerr << SEPARATOR << std::endl;
}

bool test_attributes(NinjaTrap defaultNinja, std::string name)
{
	int attributesCorrectValues[] = {60, 60, 120, 120, 1, 60, 5, 0};
	int attributesRealValues[] = {
		defaultNinja.getHP(),			defaultNinja.getMaxHP(),
		defaultNinja.getEnergyPoint(),	defaultNinja.getMaxEnergyPoint(),
		defaultNinja.getLevel(),		defaultNinja.getMeleeAttack(),
		defaultNinja.getRangedAttack(), defaultNinja.getArmorDamageReduction()};

	// Test Name
	if (name != defaultNinja.getName())
	{
		std::cerr << defaultNinja.getName() << " != " << name << std::endl;

		return false;
	}

	// Test attributes values
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

bool test_assignation(void)
{
	// Test copy and assignation
	NinjaTrap ninja = NinjaTrap("ninja");
	NinjaTrap copyNinja = NinjaTrap(ninja);
	NinjaTrap assignationNinja = ninja;

	bool result = (copyNinja == ninja) && (ninja == assignationNinja) &&
				  (copyNinja == assignationNinja);
	show_result("Assignation test: ", result);

	return result;
}

bool test_constructors(void)
{
	std::cout << std::endl << "TEST CONSTRUCTORS" << std::endl << std::endl;
	NinjaTrap defaultNinja = NinjaTrap();
	NinjaTrap damien = NinjaTrap("Damien");

	bool result = test_attributes(defaultNinja, "Default");
	show_result("Test attributes default: ", result);

	result = test_attributes(damien, "Damien");
	show_result("Test attributes normal constructor: ", result);

	return result;
}

int main(void)
{
	return (test_constructors() && test_assignation()) ? 0 : 1;
}
