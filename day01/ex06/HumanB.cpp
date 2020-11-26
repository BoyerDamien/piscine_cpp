/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:03:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 11:25:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"
#include "./Weapon.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {
  std::cout << name << " was created" << std::endl;
}

HumanB::~HumanB() { std::cout << this->_name << " was destroyed" << std::endl; }

void HumanB::attack(void) const {
  if (this->_weapon) {
    std::cout << this->_name << " attacks with his " << this->_weapon->getType()
              << std::endl;
  } else {
    std::cout << this->_name << " has no weapon" << std::endl;
  }
}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
