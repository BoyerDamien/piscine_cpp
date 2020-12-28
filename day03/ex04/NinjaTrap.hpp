/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:53:25 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/28 19:40:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class NinjaTrap : public ClapTrap
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
};

#endif
