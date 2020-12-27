/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 17:36:26 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  private:
	int _energyPoint;
	int _maxEnergyPoint;
	int _level;
	int _meleeAttack;
	std::string _name;

  public:
	// Canonical form
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	virtual ~FragTrap(void);
	FragTrap &operator=(const FragTrap &);

	// Methods
	void rangedAttack(const std::string &target);
	void vaulthunter_dot_exe(std::string const &target);
};

#endif
