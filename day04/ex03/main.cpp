/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:42:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 12:57:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./Character.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"
#include "./MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

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

bool test_materia_methods(void)
{
	IMateriaSource *src = new MateriaSource();

	AMateria *tmp = src->createMateria("cure");

	int result = tmp == NULL;

	tmp = src->createMateria("ice");

	result = result && tmp == NULL;

	tmp = src->createMateria("gtrhy");

	result = result && tmp == NULL;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("cure");
	result = result && tmp != NULL && tmp->getType() == "cure";

	delete tmp;

	tmp = src->createMateria("ice");
	result = result && tmp != NULL && tmp->getType() == "ice";

	delete tmp;
	delete src;
	return result;
}

bool test_materia_assignations(void)
{
	MateriaSource src;

	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	MateriaSource src2(src);
	MateriaSource src3 = src2;

	return src == src2 && src2 == src3;
}

bool test_character_methods(void)
{
	IMateriaSource *src = new MateriaSource();
	ICharacter *moi = new Character("moi");
	ICharacter *bob = new Character("bob");
	AMateria *tmp;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	moi->equip(tmp);
	tmp = src->createMateria("cure");
	moi->equip(tmp);

	moi->use(0, *bob);
	moi->use(1, *bob);

	delete bob;
	delete moi;
	delete src;
	return true;
}

bool test_character_assignations(void)
{
	Character bob("bob");
	bob.equip(new Cure());
	bob.equip(new Cure());
	bob.equip(new Ice());
	bob.equip(new Ice());
	Character bob2(bob);
	Character bob3 = bob;

	bob.unequip(0);
	Character bob4 = bob;

	return bob == bob2 && bob2 == bob3 && !(bob4 == bob3);
}

int main()
{
	// Test materia
	show_result("Test materia methods", test_materia_methods());
	show_result("Test materia assignations", test_materia_assignations());

	// Test character
	show_result("Test character methods", test_character_methods());
	show_result("Test character assignations", test_materia_assignations());
	return 0;
}
