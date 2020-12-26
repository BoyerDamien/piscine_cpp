/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:27:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:36:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieEvent.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

ZombieEvent::ZombieEvent(int type) : _type(type)
{
	std::cout << "ZombieEvent with type " << _type << " was created"
			  << std::endl;
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "ZombieEvent with type " << this->_type << " was destroyed"
			  << std::endl;
}

void ZombieEvent::setZombieType(int type)
{
	if (type > 0 && type < 4)
	{
		this->_type = type;
	}
}

Zombie *ZombieEvent::newZombie(std::string name) const
{
	return new Zombie(name, this->_type);
}

int ZombieEvent::_randomNumber(const int begin, const int end) const
{
	return begin + rand() % (end - begin);
}

std::string ZombieEvent::_randomString(size_t length) const
{
	const char alphanum[] = "abcdef0123456789";
	std::string result = "";
	for (size_t i = 0; i < length; i++)
	{
		result.push_back(alphanum[this->_randomNumber(0, 16)]);
	}
	return result;
}

Zombie ZombieEvent::randomChump(void) const
{
	return Zombie(this->_randomString(5), this->_type);
}
