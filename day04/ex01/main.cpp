/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:18:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 10:21:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Enemy.hpp"
#include "./PlasmaRifle.hpp"
#include "Character.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

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

/******************************************************************************
 *				Weapons tests
 *****************************************************************************/
bool test_weapons_attributes(void)
{
	PlasmaRifle plasma;
	PowerFist power;

	int result1 = plasma.getAPCost() == 5 && plasma.getDamage() == 21 &&
				  plasma.getName() == "Plasma Rifle";

	int result2 = power.getAPCost() == 8 && power.getDamage() == 50 &&
				  power.getName() == "Power Fist";

	return result1 && result2;
}

bool test_weapons_assignation(void)
{
	PlasmaRifle plasma1;
	PlasmaRifle plasma2(plasma1);
	PlasmaRifle plasma3 = plasma2;

	int result1 = plasma1 == plasma2 && plasma2 == plasma3;

	PowerFist power1;
	PowerFist power2(power1);
	PowerFist power3 = power2;

	int result2 = power1 == power2 && power2 == power3;

	return result2 && result1;
}

bool test_weapons_methods(void)
{
	PlasmaRifle plasma;
	PowerFist power;

	plasma.attack();
	power.attack();

	return true;
}

/******************************************************************************
 *				Enemy tests
 *****************************************************************************/
bool test_enemy_attributes(void)
{
	RadScorpion scorp;
	SuperMutant mut;

	int result1 = scorp.getHP() == 80 && scorp.getType() == "Rad Scorpion";
	int result2 = mut.getHP() == 170 && mut.getType() == "Super Mutant";

	return result1 && result2;
}

bool test_enemy_assignations(void)
{
	RadScorpion scorp1;
	RadScorpion scorp2(scorp1);
	RadScorpion scorp3 = scorp2;
	SuperMutant mut1;
	SuperMutant mut2(mut1);
	SuperMutant mut3 = mut2;

	bool result1 = scorp1 == scorp2 && scorp2 == scorp3;
	bool result2 = mut1 == mut2 && mut2 == mut3;

	return result1 && result2;
}

bool test_enemy_methods(void)
{
	RadScorpion scorp;
	SuperMutant mut;

	scorp.takeDamage(20);

	bool result1 = scorp.getHP() == 60;

	scorp.takeDamage(60);
	scorp.takeDamage(10);

	mut.takeDamage(123);

	bool result2 = mut.getHP() == 50;

	mut.takeDamage(53);
	mut.takeDamage(13);

	return result2 && result1;
}
/******************************************************************************
 *				Character tests
 *****************************************************************************/

bool test_character_attributes(void)
{
	Character moi("moi");
	PlasmaRifle *plasma = new PlasmaRifle;

	moi.equip(plasma);
	return moi.getAP() == 40 && moi.getName() == "moi" &&
		   moi.getWeapon() == plasma;
}

bool test_character_assignations(void)
{
	Character moi2("moi2");
	Character moi3 = moi2;

	return moi2 == moi3;
}

bool test_character_methods(void)
{
	Character moi("moi");
	Enemy *scorp = new RadScorpion();
	Enemy *mut = new SuperMutant();
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	moi.equip(pr);
	moi.attack(scorp);

	bool result = scorp->getHP() == 80 - pr->getDamage();
	result = result && moi.getAP() == 40 - pr->getAPCost();

	moi.attack(mut);
	result = result && mut->getHP() == 173 - pr->getDamage();
	result = result && moi.getAP() == 30;

	moi.recoveryAP();
	result = result && moi.getAP() == 40;

	moi.equip(pf);

	moi.attack(scorp);
	result = result && scorp->getHP() == 80 - pr->getDamage() - pf->getDamage();
	result = result && moi.getAP() == 40 - pf->getAPCost();

	delete pr;
	delete scorp;
	delete mut;
	return result;
}

int main()
{
	// Test weapons
	show_result("Test weapons attributes", test_weapons_attributes());
	show_result("Test weapons assignation", test_weapons_assignation());
	show_result("Test weapons methods", test_weapons_methods());

	// Test Enemy
	show_result("Test enemy attributes", test_enemy_attributes());
	show_result("Test enemy assignations", test_enemy_assignations());
	show_result("Test enemy methods", test_enemy_methods());

	// Test Character
	show_result("Test character attributes", test_character_attributes());
	show_result("Test character assignations", test_character_assignations());
	show_result("Test character methods", test_character_methods());
	return 0;
}
