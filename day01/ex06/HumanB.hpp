/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:58:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:21:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"
#include <iostream>

class HumanB
{

  private:
	const Weapon *_weapon;
	const std::string _name;

  public:
	HumanB(const std::string);
	~HumanB();
	void attack(void) const;
	void setWeapon(Weapon &);
};

#endif
