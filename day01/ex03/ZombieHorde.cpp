/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:15:48 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:20:14 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieHorde.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

ZombieHorde::ZombieHorde(int n) : _n(n)
{
	if (n > 0)
	{
		this->_horde = new Zombie *[n];
		for (int i = 0; i < n; i++)
		{
			this->_horde[i] = this->_newZombie();
		}
		std::cout << "A new Zombie horde was created" << std::endl;
	}
	else
	{
		std::cerr << "No Zombie horde was created" << std::endl;
	}
}

ZombieHorde::~ZombieHorde()
{
	if (this->_n > 0)
	{
		for (int i = 0; i < this->_n; i++)
		{
			delete this->_horde[i];
		}
		delete[] this->_horde;
		std::cout << "A Zombie horde was destroyed" << std::endl;
	}
}

int ZombieHorde::_randomNumber(const int begin, const int end) const
{
	return begin + rand() % (end - begin);
}

std::string ZombieHorde::_randomString(size_t length) const
{
	const char alphanum[] = "abcdef0123456789";
	std::string result = "";
	for (size_t i = 0; i < length; i++)
	{
		result.push_back(alphanum[this->_randomNumber(0, 16)]);
	}
	return result;
}

Zombie *ZombieHorde::_newZombie(void) const
{
	return new Zombie(this->_randomString(5), this->_randomNumber(1, 5));
}

void ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_n; i++)
	{
		this->_horde[i]->announce();
	}
}
