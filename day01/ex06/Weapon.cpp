/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:47:18 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 10:51:50 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type) {
  std::cout << "A weapon of type: " << this->_type << " was created"
            << std::endl;
}

Weapon::~Weapon() {
  std::cout << "A weapon of type: " << this->_type << " was destroyed"
            << std::endl;
}

const std::string &Weapon::getType(void) const { return this->_type; }

void Weapon::setType(const std::string type) { this->_type = type; }
