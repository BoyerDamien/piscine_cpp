/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/27 16:26:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

class FragTrap {

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
  FragTrap(std::string name);
  FragTrap(const FragTrap &);
  ~FragTrap(void);

  FragTrap &operator=(const FragTrap &);
  void rangedAttack(std::string const &target);
  void meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const &target);

  std::string getName(void) const;
  int getHP(void) const;
  int getLevel(void) const;
  int getEnergyPoint(void) const;
};

std::ostream &operator<<(std::ostream &, FragTrap const &);
