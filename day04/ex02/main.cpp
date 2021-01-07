/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:13:29 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 11:17:10 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AssaultTerminator.hpp"
#include "./Squad.hpp"
#include "./TacticalMarine.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
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

bool test_squad_attributes(void)
{
	ISquad *vlc = new Squad;
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;

	vlc->push(bob);
	vlc->push(jim);
	std::cout << vlc << std::endl;

	int result = vlc->getCount() == 2;

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine *cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	return result;
}

bool test_squad_assignations(void)
{
	Squad vlc1;

	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;

	vlc1.push(bob);
	vlc1.push(jim);

	Squad vlc2(vlc1);
	Squad vlc3 = vlc2;

	return vlc1.getCount() == vlc2.getCount() &&
		   vlc2.getCount() == vlc3.getCount();
}

bool test_marine_assignations(void)
{
	TacticalMarine mar1;
	TacticalMarine mar2(mar1);
	TacticalMarine mar3 = mar2;

	AssaultTerminator as1;
	AssaultTerminator as2(as1);
	AssaultTerminator as3 = as2;

	return true;
}

bool test_marine_methods(void)
{
	TacticalMarine mar;

	mar.battleCry();
	mar.meleeAttack();
	mar.rangedAttack();

	AssaultTerminator as;
	as.battleCry();
	as.meleeAttack();
	as.rangedAttack();

	ISpaceMarine *marClone = mar.clone();
	marClone->battleCry();
	marClone->meleeAttack();
	marClone->rangedAttack();

	ISpaceMarine *asClone = as.clone();
	asClone->battleCry();
	asClone->meleeAttack();
	asClone->rangedAttack();

	delete marClone;
	delete asClone;
	return true;
}

int main(void)
{
	// Test squad
	show_result("Test squad attributes", test_squad_attributes());
	show_result("Test squad assignation", test_squad_assignations());

	// Test Marine
	show_result("Test marine assignation", test_marine_assignations());
	show_result("Test marine methods", test_marine_methods());
	return 0;
}
