/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:48:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 17:25:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <ostream>

class ClapTrap
{
  protected:
	int _hitPoint;
	int _maxHitPoint;
	int _energyPoint;
	int _maxEnergyPoint;
	int _level;
	int _meleeAttack;
	int _rangedAttack;
	int _armorDamageReduction;
	std::string _name;

  public:
	// Canonical form
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &);

	// Methods
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(int amount);
	void beRepaired(int amount);
	std::string getName(void) const;
	int getHP(void) const;
	int getLevel(void) const;
	int getEnergyPoint(void) const;
};

#endif
