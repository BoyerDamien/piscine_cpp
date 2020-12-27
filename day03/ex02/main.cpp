/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 12:37:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

int main(void)
{
	{
		std::string target = "téo";
		FragTrap defaultFrag = FragTrap();
		defaultFrag.meleeAttack(target);
		FragTrap damien = FragTrap("Damien");
		damien.meleeAttack(target);
		damien.rangedAttack(target);
		damien.vaulthunter_dot_exe(target);
		damien.vaulthunter_dot_exe(target);
		damien.takeDamage(105);
		damien.meleeAttack(target);
		FragTrap fromDamien = FragTrap(damien);
		fromDamien.meleeAttack(target);

		damien = defaultFrag;
		defaultFrag = fromDamien;
		fromDamien = damien;
	}
	{
		std::string target = "téo";
		ScavTrap defaultScav = ScavTrap();
		defaultScav.meleeAttack(target);
		ScavTrap damien = ScavTrap("Damien");
		damien.meleeAttack(target);
		damien.rangedAttack(target);
		damien.challengeNewcomer();
		damien.challengeNewcomer();
		damien.takeDamage(105);
		damien.meleeAttack(target);
		ScavTrap fromDamien = ScavTrap(damien);
		fromDamien.meleeAttack(target);

		defaultScav = damien;
		damien = fromDamien;
		fromDamien = defaultScav;
	}
	return 0;
}
