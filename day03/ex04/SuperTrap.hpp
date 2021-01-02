/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:48:09 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 11:43:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include "./FragTrap.hpp"
#include "./NinjaTrap.hpp"
#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap
{
  public:
	// Canonical form
	SuperTrap(void);
	SuperTrap(std::string);
	SuperTrap(const SuperTrap &);
	virtual ~SuperTrap(void);
	SuperTrap &operator=(const SuperTrap &);

	// Methods
	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;
};

#endif
