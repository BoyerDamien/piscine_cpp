/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:09 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 10:59:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
	// Canonical form
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	virtual ~FragTrap(void);
	FragTrap &operator=(const FragTrap &);

	// Methods
	virtual void vaulthunter_dot_exe(std::string const &target);
	virtual void rangedAttack(const std::string &target);
};

#endif
