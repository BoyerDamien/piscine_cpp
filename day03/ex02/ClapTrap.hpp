/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:48:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 18:50:02 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <ostream>

class ClapTrap
{
  protected:
	std::string _name;
	int _level;
	int _hitPoint;
	int _maxHitPoint;
	int _energyPoint;
	int _maxEnergyPoint;
	int _meleeAttack;
	int _rangedAttack;
	int _armorDamageReduction;

  public:
	// Canonical form
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &);

	// Methods
	virtual void rangedAttack(std::string const &target);
	virtual void meleeAttack(std::string const &target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

	// Getters
	virtual std::string getName(void) const;
	virtual int getHP(void) const;
	virtual int getMaxHP(void) const;
	virtual int getEnergyPoint(void) const;
	virtual int getMaxEnergyPoint(void) const;
	virtual int getLevel(void) const;
	virtual int getMeleeAttack(void) const;
	virtual int getRangedAttack(void) const;
	virtual int getArmorDamageReduction(void) const;
};

bool operator==(const ClapTrap &, const ClapTrap &);

#endif
