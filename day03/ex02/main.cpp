/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 18:21:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::string target = "téo";

	/**************************************************************************
	 *                          FRAGTRAP TEST
	 *************************************************************************/
	{
		std::cout << std::endl
				  << std::endl
				  << "FRAGTRAP TEST" << std::endl
				  << std::endl;

		// Constructors test
		FragTrap defaultFrag = FragTrap();	  //  default constructor
		FragTrap frag = FragTrap("FragTrap"); //  simple constructor
		FragTrap fromFrag = FragTrap(frag);	  //  copy constructor

		std::cout << std::endl;

		// Methods test
		frag.meleeAttack(target);
		frag.rangedAttack(target);
		frag.vaulthunter_dot_exe(target);
		frag.takeDamage(30);

		std::cout << std::endl;

		fromFrag.meleeAttack(target);
		defaultFrag.meleeAttack(target);

		std::cout << std::endl;

		// Assignation test
		frag = defaultFrag;
		defaultFrag = fromFrag;
		fromFrag = frag;

		std::cout << std::endl;
	}

	/**************************************************************************
	 *                          SCAVTRAP TEST
	 *************************************************************************/
	{
		std::cout << std::endl
				  << std::endl
				  << "SCAVTRAP TEST" << std::endl
				  << std::endl;

		// Constructors test
		ScavTrap defaultScav = ScavTrap();	  // default constructor
		ScavTrap scav = ScavTrap("ScavTrap"); // simple constructor
		ScavTrap fromScav = ScavTrap(scav);	  // copy constructor

		std::cout << std::endl;

		// Methods test
		scav.meleeAttack(target);
		scav.rangedAttack(target);
		scav.challengeNewcomer();
		fromScav.meleeAttack(target);
		scav.takeDamage(30);

		std::cout << std::endl;

		// Assignation test
		defaultScav = scav;
		scav = fromScav;
		fromScav = defaultScav;

		std::cout << std::endl;
	}
	return 0;
}
