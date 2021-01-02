/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:53:25 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:03:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
  public:
	// Canonical form
	NinjaTrap(void);
	NinjaTrap(const std::string name);
	NinjaTrap(const NinjaTrap &);
	virtual ~NinjaTrap(void);
	NinjaTrap &operator=(const NinjaTrap &);

	// Methods
	virtual void ninjaShoeBox(const ClapTrap &) const;
	virtual void ninjaShoeBox(const ScavTrap &) const;
	virtual void ninjaShoeBox(const NinjaTrap &) const;
	virtual void ninjaShoeBox(const FragTrap &) const;
	void meleeAttack(const std::string &);
};

#endif
