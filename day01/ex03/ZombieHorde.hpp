/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:16:31 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/24 11:55:14 by dboyer           ###   ########.fr       */
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
  int _n;
  Zombie **_horde;
  Zombie *_newZombie(void) const;
  int _randomNumber(const int, const int) const;
  std::string _randomString(size_t) const;

public:
  ZombieHorde(int);
  ~ZombieHorde();

  void announce(void) const;
};

#endif
