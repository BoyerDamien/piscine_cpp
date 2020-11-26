/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:15:26 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/25 13:04:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, int type) : _name(name), _type(type) {
  std::cout << "The zombie with name " << name << " and type " << type
            << " was created" << std::endl;
}

Zombie::~Zombie() {
  std::cout << "The zombie with name " << this->_name << " and type "
            << this->_type << " was destroyed" << std::endl;
}

void Zombie::advert(void) const {
  std::cout << this->_name << " " << this->_type << " Braiiiiiiinnnssss ..."
            << std::endl;
}

void Zombie::announce(void) const {
  std::cout << "je suis le zombie " << this->_name << " !" << std::endl;
}
