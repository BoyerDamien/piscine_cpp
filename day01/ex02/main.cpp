/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:10:14 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:19:34 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieEvent.hpp"
#include "Zombie.hpp"

void test(int type)
{
	std::cout << std::endl << "Test pour le type " << type << std::endl;
	ZombieEvent event = ZombieEvent(type);
	Zombie zombieOnTheStack = event.randomChump();
	Zombie *zombieOnTheHeap = event.newZombie("test");

	zombieOnTheStack.advert();
	zombieOnTheStack.announce();

	zombieOnTheHeap->advert();
	zombieOnTheHeap->announce();
	delete zombieOnTheHeap;
}

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		test(i);
	}
	return 0;
}
