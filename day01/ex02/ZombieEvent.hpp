/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:24:51 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:19:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include "./Zombie.hpp"
#include <iostream>

class ZombieEvent
{

  private:
	int _type;
	int _randomNumber(const int begin, const int end) const;

  public:
	ZombieEvent(int);
	~ZombieEvent();

	void setZombieType(int);
	Zombie *newZombie(std::string name) const;
	Zombie randomChump(void) const;
	std::string _randomString(size_t length) const;
};

#endif
