/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:15:48 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 09:07:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieHorde.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>

ZombieHorde::ZombieHorde(size_t n) : _n(n) {
  this->_horde = new Zombie *[n];
  for (int i = 0; i < n; i++) {
    this->_horde[i] = this->_newZombie();
  }
  std::cout << "A new Zombie horde was created" << std::endl;
}

ZombieHorde::~ZombieHorde() {
  for (size_t i = 0; i < this->_n; i++) {
    delete this->_horde[i];
  }
  delete[] this->_horde;
  std::cout << "A Zombie horde was destroyed" << std::endl;
}

int ZombieHorde::_randomNumber(const int begin, const int end) const {
  return begin + rand() % (end - begin);
}

std::string ZombieHorde::_randomString(size_t length) const {
  const char alphanum[] = "abcdef0123456789";
  std::string result = "";
  for (int i = 0; i < length; i++) {
    result.push_back(alphanum[this->_randomNumber(i, 16)]);
  }
  return result;
}

Zombie *ZombieHorde::_newZombie(void) const {
  Zombie *ret = new Zombie(this->_randomString(5), this->_randomNumber(1, 5));
  return ret;
}

void ZombieHorde::announce(void) const {
  for (size_t i = 0; i < this->_n; i++) {
    this->_horde[i]->announce();
  }
}
