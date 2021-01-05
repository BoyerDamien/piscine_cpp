/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:18:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 15:20:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Enemy.hpp"
#include "./PlasmaRifle.hpp"
#include "Character.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"

int main()
{
	Character *moi = new Character("moi");
	std::cout << *moi;

	Enemy *b = new RadScorpion();
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;

	delete moi;
	delete b;
	delete pr;
	delete pf;

	return 0;
}
