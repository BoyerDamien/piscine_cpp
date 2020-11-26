/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:58:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 11:08:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "./Weapon.hpp"
#include <iostream>

class HumanA {

private:
  const Weapon &_weapon;
  const std::string _name;

public:
  HumanA(const std::string, const Weapon &);
  ~HumanA();
  void attack(void) const;
};

#endif
