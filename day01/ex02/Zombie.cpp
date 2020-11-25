/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:15:26 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/24 18:35:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, int type) : _name(name), _type(type) {}

void Zombie::advert(void) const {
  std::cout << this->_name << " " << this->_type << " Braiiiiiiinnnssss ..."
            << std::endl;
}

void Zombie::announce(void) const {
  std::cout << "je suis le zombie " << this->_name << " !" << std::endl;
}
