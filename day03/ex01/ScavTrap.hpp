/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 11:46:29 by dboyer           ###   ########.fr       */
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
	std::string getName(void) const;
	int getHP(void) const;
	int getLevel(void) const;
	int getEnergyPoint(void) const;
};

#endif
