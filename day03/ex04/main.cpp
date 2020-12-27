/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 17:39:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./NinjaTrap.hpp"
#include "./ScavTrap.hpp"
#include "./SuperTrap.hpp"

int main(void)
{
	std::string target = "téo";

	SuperTrap damien = SuperTrap();
	std::cout << damien.getHP() << std::endl;
	damien.rangedAttack(target);

	SuperTrap test = damien;
	test.rangedAttack(target);
	/*FragTrap defaultFrag = FragTrap();
	ScavTrap defaultScav = ScavTrap();
	ClapTrap defaultClap = ClapTrap();
	NinjaTrap defaultNinja = NinjaTrap();
	NinjaTrap damien = NinjaTrap("damien");

	defaultNinja.ninjaShoeBox(defaultFrag);
	defaultNinja.ninjaShoeBox(defaultScav);
	defaultNinja.ninjaShoeBox(defaultClap);
	defaultNinja.ninjaShoeBox(defaultNinja);
	defaultNinja.ninjaShoeBox(damien);

	damien.meleeAttack("test");
	damien.rangedAttack("test");
	damien.takeDamage(105);
	NinjaTrap fromDamien = NinjaTrap(damien);
	fromDamien.meleeAttack("test");

	defaultNinja = damien;
	damien = fromDamien;
	fromDamien = defaultNinja;*/
	return 0;
}
