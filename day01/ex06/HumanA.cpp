/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:03:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 11:08:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"
#include "./Weapon.hpp"

HumanA::HumanA(const std::string name, const Weapon &weapon)
    : _name(name), _weapon(weapon) {
  std::cout << name << " with a weapon of type: " << weapon.getType()
            << " was created" << std::endl;
}

HumanA::~HumanA() {
  std::cout << this->_name
            << " with a weapon of type: " << this->_weapon.getType()
            << " was destroyed" << std::endl;
}

void HumanA::attack(void) const {
  std::cout << this->_name << " attacks with his " << this->_weapon.getType()
            << std::endl;
}
