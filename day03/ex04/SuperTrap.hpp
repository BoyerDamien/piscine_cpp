/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:48:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 19:42:42 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include "./FragTrap.hpp"
#include "./NinjaTrap.hpp"
#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap
{
  private:
	using FragTrap::_armorDamageReduction;
	using FragTrap::_hitPoint;
	using FragTrap::_level;
	using FragTrap::_maxHitPoint;
	using FragTrap::_name;
	using FragTrap::_rangedAttack;
	using NinjaTrap::_energyPoint;
	using NinjaTrap::_maxEnergyPoint;
	using NinjaTrap::_meleeAttack;

  public:
	// Canonical form
	SuperTrap(void);
	SuperTrap(std::string);
	SuperTrap(const SuperTrap &);
	~SuperTrap(void);
	SuperTrap &operator=(const SuperTrap &);

	// Methods
	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;
};

#endif
