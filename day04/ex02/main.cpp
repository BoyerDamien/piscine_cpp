/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:13:29 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 12:53:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AssaultTerminator.hpp"
#include "./Squad.hpp"
#include "./TacticalMarine.hpp"
#include <iostream>

int main(void)
{
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;
	ISquad *vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);

	std::cout << vlc << std::endl;

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine *cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	return 0;
}
