/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:48:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 17:14:45 by dboyer           ###   ########.fr       */
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
	std::string _name;

  public:
	// Canonical form
	SuperTrap(void);
	SuperTrap(std::string);
	SuperTrap(const SuperTrap &);
	~SuperTrap(void);
	// SuperTrap &operator=(const SuperTrap &);

	// Methods
	/*using FragTrap::operator=;
	using FragTrap::beRepaired;
	using FragTrap::getEnergyPoint;
	using FragTrap::getHP;
	using FragTrap::getLevel;
	using FragTrap::getName;
	using FragTrap::rangedAttack;
	using FragTrap::takeDamage;*/
	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;
};

#endif
