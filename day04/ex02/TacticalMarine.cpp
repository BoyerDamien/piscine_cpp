/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:46:58 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 12:02:59 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./TacticalMarine.hpp"
#include "ISpaceMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for action !" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &other)
{
	(void)other;
	std::cout << "Tactical Marine ready for action !" << std::endl;
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &other)
{
	(void)other;
	return *this;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh ..." << std::endl;
}

/******************************************************************************
 *				Methods
 *****************************************************************************/

ISpaceMarine *TacticalMarine::clone() const
{
	return new TacticalMarine();
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the Holy PLOT !" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}
