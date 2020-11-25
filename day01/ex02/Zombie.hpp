/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:11:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/24 18:50:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

private:
  std::string _name;
  int _type;

public:
  void advert(void) const;
  Zombie(std::string, int);
  void announce(void) const;
};

#endif
