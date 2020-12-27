/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 11:41:50 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

  public:
	// Canonical form
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &);
	virtual ~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &);

	// Methods
	void challengeNewcomer(void) const;
};

#endif
