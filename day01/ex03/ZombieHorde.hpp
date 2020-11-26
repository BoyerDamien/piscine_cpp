/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:16:31 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/25 14:05:59 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include "./Zombie.hpp"
#include <bits/c++config.h>
#include <cstddef>
#include <iostream>
#include <string>

class ZombieHorde {

private:
  size_t _n;
  Zombie **_horde;
  Zombie *_newZombie(void) const;
  int _randomNumber(const int, const int) const;
  std::string _randomString(size_t) const;

public:
  ZombieHorde(size_t);
  ~ZombieHorde();

  void announce(void) const;
};

#endif
