/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:54:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <ostream>

class FragTrap
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
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	~FragTrap(void);

	FragTrap &operator=(const FragTrap &);
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);

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

bool operator==(const FragTrap &, const FragTrap &);
#endif
