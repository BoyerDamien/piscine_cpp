/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 12:01:52 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <ostream>

class ScavTrap
{

  private:
	int _hitPoint;
	int _maxHitPoint;
	int _energyPoint;
	int _maxEnergyPoint;
	int _level;
	std::string _name;
	int _meleeAttack;
	int _rangedAttack;
	int _armorDamageReduction;

  public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &);
	~ScavTrap(void);

	ScavTrap &operator=(const ScavTrap &);
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void) const;

	// Getters
	std::string getName(void) const;
	int getHP(void) const;
	int getMaxHP(void) const;
	int getEnergyPoint(void) const;
	int getMaxEnergyPoint(void) const;
	int getLevel(void) const;
	int getMeleeAttack(void) const;
	int getRangedAttack(void) const;
	int getArmorDamageReduction(void) const;
};

bool operator==(const ScavTrap &, const ScavTrap &);

#endif
