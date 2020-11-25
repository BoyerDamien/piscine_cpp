/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:27:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/25 11:51:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieEvent.hpp"
#include <cstddef>
#include <ctime>
#include <sstream>
#include <string>

void ZombieEvent::setZombieType(int type) {
  if (type > 0 && type < 4) {
    this->_type = type;
  }
}

Zombie *ZombieEvent::newZombie(std::string name) const {
  Zombie *ret = new Zombie(name, this->_type);
  return ret;
}

int ZombieEvent::_randomNumber(const int begin, const int end) const {
  return begin + std::time(0) % (end - begin);
}

std::string ZombieEvent::randomString(size_t length) const {
  const char alphanum[] = "abcdef0123456789";
  std::string result = "";
  for (int i = 0; i < length; i++) {
    result.push_back(alphanum[this->_randomNumber(0, 16)]);
  }
  std::cout << result << std::endl;
  return result;
}
